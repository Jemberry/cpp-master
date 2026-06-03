#include <iostream>
#include <memory>

using namespace std;

/*
智能指针和多态结合
*/

class Father
{
public:
    // 虚函数 (纯虚函数)
    virtual void func() = 0;
};

class Son : public Father
{
public:
    // 虚函数
    virtual void func() override
    {
        cout << "Son::func()" << endl;
    }
};

void test1()
{
    // Father * f = new Son{};
    // f->func();
    // <父类型>            { 子类型的对象 }
    unique_ptr<Father> up { new Son{} };
    // 通过智能指针调用同名的虚函数
    up->func();
    (*up).func();
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}

