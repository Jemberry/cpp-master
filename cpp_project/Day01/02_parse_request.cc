// 角色：服务器
// 任务：解析Http请求报文
// 格式：
// <请求方法> <URI> <版本>
// <头部字段>
// ...
//
// <主体>

#include <iostream>
#include <wfrest/HttpServer.h>
#include <workflow/HttpUtil.h> // Utility

using namespace std;
using namespace protocol;
using namespace wfrest;

int main()
{
    // 1. 创建HttpServer
    HttpServer server;

    // 2. 注册路由
    server.GET("/*", [](const HttpReq* req, HttpResp* resp) {
        // a. 解析请求
        cout << req->get_method() << " "
             << req->get_request_uri() << " "
             << req->get_http_version() << "\r\n";

        // 解析请求头
        HttpHeaderCursor cursor(req);
        string name;
        string value;
        while (cursor.next(name, value)) {
            // 解析成功
            cout << name << ": " << value << endl;
        }
        cout << "\r\n";

        // b. 处理业务逻辑
        // c. 生成响应
    });

    server.POST("/*", [](const HttpReq* req, HttpResp* resp) {
        // a. 解析请求
        cout << req->get_method() << " "
             << req->get_request_uri() << " "
             << req->get_http_version() << "\r\n";

        // 解析请求头
        HttpHeaderCursor cursor(req);
        string name;
        string value;
        while (cursor.next(name, value)) {
            // 解析成功
            cout << name << ": " << value << endl;
        }
        cout << "\r\n";

        // 解析请求体
        // Q: 如何解析二进制的主体？
        cout << req->body() << endl;
    });

    // 3. 启动服务器：绑定通配符地址，监听8888端口
    if (server.start(8888) == 0) {
        getchar(); // 按Enter键退出
        server.stop();
    } else {
        cerr << "Error: Server start FAILED!" << endl;
    }
}
