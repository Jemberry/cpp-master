// 解析URI
// URI: <scheme>://<authority><path>?<query>#<fragment>
// HTTP服务器:
//     绑定通配符地址 0.0.0.0
//     监听众所周知的端口

#include <iostream>
#include <map>
#include <wfrest/HttpServer.h>

using namespace std;
using namespace wfrest;

int main()
{
    // 1. 创建HTTP服务器
    HttpServer server;

    // 2. 注册路由
    server.GET("/*", [](const HttpReq* req, HttpResp* resp) {
        // 解析URI: <path>?<query>
        cout << req->get_request_uri() << endl;
        // 解析<path>
        cout << "full_path: " << req->full_path() << endl; // 路由：/*
        cout << "match_path: " << req->match_path() << endl; // 匹配的路径: *号匹配的部分
        cout << "current_path: " << req->current_path() << endl; // 用户输入的路径
        // 解析查询参数
        const map<string, string>& querys = req->query_list();
        // 基于范围的for循环
        // for (const auto& p : querys) {
        //     string key = p.first;
        //     string val = p.second;
        //     cout << key << ": " << val << endl;
        // }

        // C++17特性：结构化绑定
        for (const auto& [key, val] : querys) {
            cout << key << ": " << val << endl;
        }
    });

    // 3. 启动服务器
    if (server.start(8888) == 0) { // server.start(): 主线程不会阻塞
        getchar(); // 按Enter退出
        server.stop(); // 让服务器有序地退出
    } else {
        // 启动失败
        cerr << "Error: server start FAILED!" << endl;
        exit(1);
    }
}
