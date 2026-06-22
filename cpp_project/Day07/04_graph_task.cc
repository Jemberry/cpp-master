#include "common.h"
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/WFGraphTask.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>

using namespace std;

void http_callback(WFHttpTask* task)
{
    int state = task->get_state();
    if (state != WFT_STATE_SUCCESS) {
        return;
    }
    const void* body;
    size_t* size = static_cast<size_t*>(task->user_data);
    task->get_resp()->get_parsed_body(&body, size);
    // [输出网页]
}

int main()
{
    // 1. 创建4个任务
    WFTimerTask* timer = WFTaskFactory::create_timer_task(3, 0, [](WFTimerTask*) {
        cout << "Timer task complete(3s)" << endl;
    });
    WFHttpTask* http1 = WFTaskFactory::create_http_task("http://www.baidu.com", 3, 3, http_callback);
    size_t size1;
    http1->user_data = &size1;

    WFHttpTask* http2 = WFTaskFactory::create_http_task("http://www.sogou.com", 3, 3, http_callback);
    size_t size2;
    http2->user_data = &size2;

    WFGoTask* display = WFTaskFactory::create_go_task("q1", [&]() {
        cout << "百度首页的大小：" << size1 << endl;
        cout << "搜狗首页的大小：" << size2 << endl;
    });

    // 2. 构建DAG图任务
    // 空图：没有任何节点
    WFGraphTask* graph = WFTaskFactory::create_graph_task([](WFGraphTask*) {
        cout << "DAG图任务完成" << endl;
    });

    // 四个孤立的节点
    // 设计模式：Wrapper（装饰者模式，包装器模式）
    WFGraphNode& a = graph->create_graph_node(timer); // 将timer添加到graph中，变成graph的一个节点
    WFGraphNode& b = graph->create_graph_node(http1);
    WFGraphNode& c = graph->create_graph_node(http2);
    WFGraphNode& d = graph->create_graph_node(display);

    // 定义节点之间的依赖关系 (Why? 运算符重载)
    a-- > b;
    b-- > d;
    c < --a;
    d < --c;

    // 3. 启动DAG图任务 (拓扑排序)
    WFFacilities::WaitGroup waitGroup(1);

    Workflow::start_series_work(graph, [&waitGroup](const SeriesWork*) {
        waitGroup.done();
    });

    // 4. 主线程等待图任务结束
    waitGroup.wait();
}
