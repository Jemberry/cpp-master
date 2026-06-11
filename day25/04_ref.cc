#include <iostream>
#include <functional>

using namespace std;

/*
std::ref / std::cref ----> 引用包装器
*/

void func(int a, int & b, const int c)
{
    // 值传递的话 修改的是变量的副本
    a++;
    b++;
    // c++;
    cout << "a:" << a << " b:" << b << " c:" << c << endl;

}

void test1()
{
    int a = 1;
    int b = 2;
    int c = 3;
    // bind的传值方式是值传递
    // auto f = bind(func, a, b, c);
    auto f = bind(func, a, std::ref(b), std::cref(c));
    // 修改传值方式 值传递---->引用传递
    // 使用引用包装器 std::ref / std::cref
    f();

    cout << "a:" << a << " b:" << b << " c:" << c << endl;

}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
