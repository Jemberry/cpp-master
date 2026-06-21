#include "common.h"
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>

using namespace std;

// Q: 如何取消周期性的定时器任务？
void timer_callback(WFTimerTask* task)
{
    int state = task->get_state();
    if (state != WFT_STATE_SUCCESS) {
        cout << "Timer Cancelled!" << endl;
        return;
    }
    cout << "Timer Triggered!" << endl;
    WFTimerTask* next = WFTaskFactory::create_timer_task("timer", 1, 0, timer_callback);
    series_of(task)->push_back(next);
}

int main()
{
    // 1. 创建有名定时器任务
    WFTimerTask* task = WFTaskFactory::create_timer_task("timer", 3, 0, timer_callback);

    // 2. 启动定时器任务
    WFFacilities::WaitGroup waitGroup(1);

    SeriesWork* series = Workflow::create_series_work(task, [&waitGroup](const SeriesWork*) {
        waitGroup.done();
    });

    series->start();
    // 3. 主线程等待
    sleep(10);
    // series->cancel();

    WFTaskFactory::cancel_by_name("timer");

    waitGroup.wait();
}
