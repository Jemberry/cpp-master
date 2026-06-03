#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::unique_ptr;

/*
 * 删除器: 回收资源
 * 针对其他资源, 文件资源, 网络资源...
 * 需要针对特殊的资源进行特殊的回收处理--->自定义删除器
 *
 */



void test1()
{
    FILE* fp = fopen("temp.txt","a+");
    string msg = "hello";
    fwrite(msg.c_str(),1, msg.size(), fp);
    // 释放文件资源
    fclose(fp);
}

// 自定义一个删除器
struct FileDeleter
{
    // operator() 重载 ---> 函数对象
    void operator()(FILE * fp)
    {
        cout << "close file" << endl;
        fclose(fp);
    }
};

//unique_ptr
void test2()
{
    unique_ptr<FILE, FileDeleter> up { fopen("temp.txt", "a+") };
    string msg = "hello";
    fwrite(msg.c_str(),1, msg.size(), up.get());

}

//shared_ptr
void test3()
{
    shared_ptr<FILE> sp { fopen("temp.txt", "a+"), FileDeleter() };
    string msg = "hello";
    fwrite(msg.c_str(),1, msg.size(), sp.get());

}

int main(int argc, char * argv[])
{
    /* test1(); */
    /* test2(); */
    test3();
    return 0;
}

