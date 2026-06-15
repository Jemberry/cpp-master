// 重定向
// 301 Moved Permanently：永久重定向
// 303 See other：跳转到结果页，第二次请求一定是GET方法
// 307 Temporary Redirect：临时重定向，保持请求方法不变

// 角色：HTTP服务器

#include <iostream>
#include <wfrest/HttpServer.h>
#include <workflow/HttpUtil.h>

using namespace std;
using namespace wfrest;

int main()
{
    // 1. 创建HTTP服务器
    HttpServer server;

    // 2. 注册路由
    /******************************************************************
     *                        301 Moved Permanently                   *
     ******************************************************************/
    server.GET("/status/301", [](const HttpReq* req, HttpResp* resp) {
        // a. 解析请求
        // b. 处理业务
        // c. 生成响应
        resp->set_status(301);
        // resp->set_status(HttpStatusMovedPermanently);
        resp->set_header_pair("Location", "/newpage/301");
    });

    server.GET("/newpage/301", [](const HttpReq* req, HttpResp* resp) {
        resp->String("GET /newpage/301"); // 设置响应体
    });

    /******************************************************************
     *                        303 See Other                           *
     ******************************************************************/
    server.GET("/status/303", [](const HttpReq* req, HttpResp* resp) {
        // a. 解析请求
        // b. 处理业务
        // c. 生成响应
        resp->set_status(303);
        // resp->set_status(HttpStatusSeeOther);
        resp->set_header_pair("Location", "/newpage/303"); // 只是设置了URI，没有设置请求方法
    });

    server.POST("/status/303", [](const HttpReq* req, HttpResp* resp) {
        // a. 解析请求
        // b. 处理业务
        // c. 生成响应
        resp->set_status(303);
        // resp->set_status(HttpStatusSeeOther);
        resp->set_header_pair("Location", "/newpage/303"); // 只是设置了URI，没有设置请求方法
    });

    server.GET("/newpage/303", [](const HttpReq* req, HttpResp* resp) {
        resp->String("GET /newpage/303"); // 设置响应体
    });

    server.POST("/newpage/303", [](const HttpReq* req, HttpResp* resp) {
        resp->String("POST /newpage/303"); // 设置响应体
    });

    /******************************************************************
     *                        307 Temporary Redirect                  *
     ******************************************************************/
    server.GET("/status/307", [](const HttpReq* req, HttpResp* resp) {
        // a. 解析请求
        // b. 处理业务
        // c. 生成响应
        resp->set_status(307);
        // resp->set_status(HttpStatusTemporaryRedirect);
        resp->set_header_pair("Location", "/newpage/307"); // 只是设置了URI，没有设置请求方法
    });

    server.POST("/status/307", [](const HttpReq* req, HttpResp* resp) {
        // a. 解析请求
        // b. 处理业务
        // c. 生成响应
        resp->set_status(307);
        // resp->set_status(HttpStatusTemporaryRedirect);
        resp->set_header_pair("Location", "/newpage/307"); // 只是设置了URI，没有设置请求方法
    });

    server.GET("/newpage/307", [](const HttpReq* req, HttpResp* resp) {
        resp->String("GET /newpage/307"); // 设置响应体
    });

    server.POST("/newpage/307", [](const HttpReq* req, HttpResp* resp) {
        resp->String("POST /newpage/307"); // 设置响应体
    });

    // 3. 启动服务器
    if (server.start(8888) == 0) {
        getchar();
        server.stop(); // 有序退出
    } else {
        cerr << "Error: Server start FAILED!" << endl;
    }
}
