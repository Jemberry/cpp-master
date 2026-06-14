// 解析响应报文
// 格式：
// <version> <status-code> <reason>
// <headers>
// ...
//
// <body>
// 角色：HTTP客户端

#include <iostream>
#include <workflow/HttpMessage.h>
#include <workflow/HttpUtil.h>
#include <workflow/WFGlobal.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>

using namespace std;
using namespace protocol;

// 解析响应报文
void http_callback(WFHttpTask* task)
{
    // 1. 判断任务是否成功
    int state = task->get_state();
    if (state != WFT_STATE_SUCCESS) {
        // 打印错误信息
        cerr << WFGlobal::get_error_string(state, task->get_error()) << endl;
        return;
    }

    // 2. 任务成功 (收到HTTP响应)
    HttpResponse* resp = task->get_resp();
    // 响应行
    cout << resp->get_http_version() << " "
         << resp->get_status_code() << " "
         << resp->get_reason_phrase() << "\r\n";
    // 响应头
    HttpHeaderCursor cursor(resp);
    string name;
    string value;
    while (cursor.next(name, value)) {
        // 解析头部成功
        cout << name << ": " << value << "\r\n";
    }
    cout << "\r\n";
    // 响应体
    const void* body; // 指向body
    size_t size; // body的大小
    resp->get_parsed_body(&body, &size);

    cout << static_cast<const char*>(body) << endl;
}

int main()
{
    // 1. 创建HTTP任务
    WFHttpTask* task = WFTaskFactory::create_http_task(
        "http://www.baidu.com", // uri: 代表互联网上的一个资源
        // "http://www.not_exist1.com",
        // "http://www.google.com",
        3, // redirect_max
        3, // retry_max
        http_callback); // 回调函数：任务完成后框架会主动调用这个函数

    // 2. 设置任务参数
    HttpRequest* req = task->get_req();
    req->set_method("GET"); // 默认是GET方法
    req->set_request_uri("/");

    // 3. 提交任务，让线程池异步执行任务
    task->start(); // 非阻塞
    cout << "任务已提交" << endl;

    // 4. 让主线程阻塞，等待任务执行完成
    getchar();

    // return 0;  --> exit(0) --> _exit(0) --> 进程退出
}
