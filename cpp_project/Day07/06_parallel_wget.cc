#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/WFGlobal.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/Workflow.h>

using namespace std;
using namespace protocol;

struct SeriesContex {
    string url;
    int state;
    int error;
    HttpResponse resp; // 特别注意：不能是指针！
};

void http_callback(WFHttpTask* task)
{
    SeriesWork* series = series_of(task);
    SeriesContex* ctx = static_cast<SeriesContex*>(series->get_context());
    ctx->state = task->get_state();
    ctx->error = task->get_error();
    ctx->resp = std::move(*task->get_resp());
}

// 按用户输入URI顺序，输出网页
void parallel_callback(const ParallelWork* parallel)
{
    for (int i = 0; i < parallel->size(); ++i) {
        const SeriesWork* series = parallel->series_at(i);
        // 获取序列的上下文
        SeriesContex* ctx = static_cast<SeriesContex*>(series->get_context());
        cout << ctx->url << ": " << endl;
        if (ctx->state != WFT_STATE_SUCCESS) {
            cout << WFGlobal::get_error_string(ctx->state, ctx->error) << endl;
        } else {
            const void* body;
            size_t size;
            ctx->resp.get_parsed_body(&body, &size);
            cout << static_cast<const char*>(body) << endl;
        }
    }
}

int main(int argc, char* argv[])
{
    // 1. 命令行参数校验
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <URI>..." << endl;
        exit(1);
    }

    // 2. 根据用户输入的URI创建HTTP任务
    ParallelWork* parallel = Workflow::create_parallel_work(parallel_callback);
    for (int i = 1; i < argc; ++i) {
        WFHttpTask* task = WFTaskFactory::create_http_task(argv[i], 3, 3, http_callback);

        SeriesWork* series = Workflow::create_series_work(task, nullptr);
        SeriesContex* ctx = new SeriesContex;
        ctx->url = argv[i];
        series->set_context(ctx);

        // 按用户输入URI的顺序添加SeriesWork
        parallel->add_series(series);
    }

    // 3. 启动ParalleWork
    WFFacilities::WaitGroup waitGroup(1);

    Workflow::start_series_work(parallel, [&waitGroup](const SeriesWork*) {
        waitGroup.done();
    });

    // 4. 让主线程等待
    waitGroup.wait();
}
