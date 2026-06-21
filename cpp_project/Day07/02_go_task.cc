#include "common.h"
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>

using namespace std;

// 引用：
// int&  --> 左值引用：只能绑定左值
// const int& --> const左值引用：既能绑定左值，也能绑定右值，但是不能修改值
// int&& --> 右值引用：只能绑定右值
// T&&   --> 通用引用：既能绑定左值，也能绑定右值
void add(int a, int b, int& c)
{
    sleep(3); // 模拟耗时计算
    c = a + b;
    cout << "add: c=" << c << endl;
}

int main()
{
    // 1. 创建WFGoTask
    int a = 3;
    int b = 4;
    int c = 0;
    WFGoTask* task = WFTaskFactory::create_go_task("q1", add, a, b, std::ref(c));
    // Q: WFGoTask没有回调函数吗？
    task->set_callback([&c](WFGoTask*) {
        cout << "[callback]: c=" << c << endl;
    });

    // 2. 启动任务
    WFFacilities::WaitGroup waitGroup(1);

    SeriesWork* series = Workflow::create_series_work(task, [&waitGroup](const SeriesWork*) {
        waitGroup.done();
    });

    series->start();
    // 3. 主线程等待
    waitGroup.wait();
    cout << "main: c=" << c << endl;
}
