#include <iostream>
#include <workflow/HttpMessage.h>
#include <workflow/WFHttpServer.h>

using namespace std;
using namespace protocol;

int main()
{
    // 1. 创建HTTP服务器
    WFHttpServer server([](WFHttpTask* task) {
        HttpResponse* resp = task->get_resp();
        resp->append_output_body("<html>Hello workflow!</html>");
    });

    // 2. 启动服务器
    if (server.start(8888) == 0) { // start server on port 8888
        getchar(); // press "Enter" to end.
        server.stop();
    } else {
        cerr << "Error: Server start FAILED!" << endl;
    }

    return 0;
}
