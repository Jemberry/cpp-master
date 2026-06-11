#include <iostream>
#include <functional>


using namespace std;

int func(int a, int b)
{
    cout << "a:" << a << " b:" << b << endl;
    return a + b;
}


// 能否使用函数指针接收bind的返回结果
void test1()
{
    func(1,2);
    cout << "------" << endl;
    using F = int (*)(int,int);
    F f = func;
    f(1,2);
    // 上下等价
    cout << "------" << endl;
    int (*f1)(int,int) = &func;
    f1(3,4);

    //能否使用函数指针接收bind的返回结果?
    // auto接收
    auto  f2 = bind(func, 10, 20);
    f2();
    cout << "-----" << endl;
    // f1 = bind(func,100,200);  不能用函数指针接收bind的结果

    // 函数指针只能接收同类型的函数 bind的返回结果 是一个函数对象

    // 如果想接收bind的返回结果--->可以使用std::function
}

// fucntion存储普通函数
void test2()
{
    // int func(int,int)
    // int (int,int) 函数类型
    // 要保持函数的签名一致 返回值 形参要一致
    std::function<int(int,int)> f3 = func;
    f3(1,2);
    cout << "-----" << endl;
    // int(int,int)---> int()
    std::function<int()> f4 = bind(func,1,2);
    f4();
}

// fucntion存储普通函数
void test3()
{
    // int func(int,int)
    // int (int,int) 函数类型
    // 要保持函数的签名一致 返回值 形参要一致
    std::function<int(int,int)> f3 = &func;
    f3(1,2);
    cout << "-----" << endl;
    // int(int,int)---> int()
    std::function<int()> f4 = bind(&func,1,2);
    f4();
}

struct Callable
{
    void operator()(int a, int b)
    {
        cout << "a:" << a << " b:" << b << endl;
        
    }
};

// function存储函数对象
void test4()
{
    // void (int,int) 函数类型
    function<void(int,int)> f1 = Callable();
    f1(1,2);
    // 使用bind改变函数形态
    // void(int,int) ---> void(int)
    function<void(int)> f2 = bind(Callable(),1, std::placeholders::_1);
    f2(100);
}

// function存储lambda
void test5()
{
    // void(int) 函数类型
    function<void(int)> f1 = [](int num)->void{
        cout << "lambda" << endl;
        cout << num << endl;
    };
    f1(100);

    // void(int) ----> void ()
    function<void()> f2 = bind([](int num)->void{
        cout << "lambda" << endl;
        cout << num << endl;
    }, 200);
    f2();
}

class MyClass
{
public:
    // 成员函数
    void func(int a, int b)
    {
        cout << "a = " << a << " b =" << b << endl;
    }
};

// function存储成员函数
void test6()
{
    MyClass obj;
    // 对象.成员函数
    obj.func(1,2);
    // 指针->成员函数调用
    MyClass * p = &obj;
    p->func(3,4);
    cout << "------" << endl;
    // void (MyClass&, int,int)
    // void (MyClass*, int,int)
    function<void(MyClass&,int,int)> f1 = &MyClass::func;
    f1(obj,10,20);

    function<void(MyClass*,int,int)> f2 = &MyClass::func;
    f2(&obj,10,20);

    // 使用bind改变形态
    //  void (MyClass&, int,int) ---> void(int,int)
    function<void(int,int)> f3 = bind(&MyClass::func,obj,std::placeholders::_1,std::placeholders::_2);
    f3(100,200);

}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test4();
    // test5();
    test6();
    return 0;
}

