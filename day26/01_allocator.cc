#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void test1()
{
    int * p1 = new int{1};
    cout << *p1 << endl;
    cout << "p1:" << p1 << endl;
   
    cout << "-------" << endl;
    // 创建空间配置器对象
    allocator<int> alloc;
    // 申请空间 allocate()
    int * p2 = alloc.allocate(1); // 1个int类型的空间
    alloc.construct(p2,2);
    cout << *p2 << endl;
    cout << "p2:" << p2 << endl;

    // 释放空间
    delete p1;
    alloc.deallocate(p2,1);
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
