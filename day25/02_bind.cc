#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;


/*
bind : 包装可调用对象, 生成一个新的可调用对象, 像函数一样进行调用

可以改变函数形态 , 把二元---->一元--->零元

*/

int add(int a, int b)
{
    cout << "a:" << a << " b:" << b << endl;
    return a + b;
}


// bind 普通函数
void test1()
{
    add(1,2);
    cout << "-----" << endl;
    // 固定add函数中的参数a = 1 b=2
    // int(int,int) -> int ()
    auto f1 = bind(add,1,2); 
    f1();
    cout << "-------" << endl;
    // std::placeholders::_1是占位符  表示第一个参数
    // std::placeholders::_2是占位符  表示第二个参数
    // 取值取决于实际的参数顺序
    auto f2 = bind(add,std::placeholders::_1,std::placeholders::_2);
    f2(100, 200); 
    cout << "-------" << endl;
    // placeholders::_2 表示第一个参数  a
    // placeholders::_1 表示第二个参数  b
    // 取值取决于实际的参数顺序
    
    auto f3 = bind(add,std::placeholders::_2, std::placeholders::_1);
    f3(300, 400); 
    cout << "-----" << endl;
    // 部分固定, 部分传递
    // a使用占位符 b固定为10
    // int (int,int) -----> int (int)  二元--->一元
    auto f4 = bind(add,std::placeholders::_1, 10);
    f4(100);
}


// bind 普通函数指针
void test2()
{
    add(1,2);
    cout << "-----" << endl;
    // 固定add函数中的参数a = 1 b=2
    // int(int,int) -> int ()
    auto f1 = bind(&add,1,2); 
    f1();
    cout << "-------" << endl;
    // std::placeholders::_1是占位符  表示第一个参数
    // std::placeholders::_2是占位符  表示第二个参数
    // 取值取决于实际的参数顺序
    auto f2 = bind(&add,std::placeholders::_1,std::placeholders::_2);
    f2(100, 200); 
    cout << "-------" << endl;
    // placeholders::_2 表示第一个参数  a
    // placeholders::_1 表示第二个参数  b
    // 取值取决于实际的参数顺序
    
    auto f3 = bind(&add,std::placeholders::_2, std::placeholders::_1);
    f3(300, 400); 
    cout << "-----" << endl;
    // 部分固定, 部分传递
    // a使用占位符 b固定为10
    // int (int,int) -----> int (int)  二元--->一元
    auto f4 = bind(&add,std::placeholders::_1, 10);
    f4(100);
}

// bind包装函数对象
struct Callable
{
    int operator()(int a,int b)
    {
        cout << "a =" << a << " b =" << b << endl;
        return a + b;
    }

};

void test3()
{
    Callable callable;
    callable(1,2);
    cout << "-----" << endl;
    // 固定了函数参数 a =  1  b = 2
    // int (int,int) ----> int ()
    auto f1 = bind(Callable(),1,2);
    f1();

    cout << "-------" << endl;
    auto f2 = bind(Callable(),std::placeholders::_1, std::placeholders::_2);
    f2(100, 200);

    cout << "-------" << endl;
    // int(int,int) ----> int (int)  二元--->一元
    auto f3 = bind(Callable(),std::placeholders::_1,20);
    f3(100);
}


// bind 包装lambda
void test4()
{
    [](int a, int b)->void{
        cout << "a:" << a << " b:" << b << endl;
    }(1,2); // 直接调用lambda
    cout << "-------" << endl;
    auto f0 = [](int a, int b)->void{
        cout << "a:" << a << " b:" << b << endl;
    }; // 使用auto接收lambda表达式 再进行调用  void (int,int)
    f0(1,2);
    cout << "-------" << endl;
    // void (int,int) ---> void ()
    auto f1 = bind([](int a, int b)->void{
        cout << "a:" << a << " b:" << b << endl;
    }, 1,2); // 使用bind绑定lambda表达式  void (int,int) ---> void ()
    f1();
    cout << "-----" << endl;
    // 使用占位符
    auto f2 = bind([](int a, int b)->void{
        cout << "a:" << a << " b:" << b << endl;
    }, 1, std::placeholders::_1); // 使用bind绑定lambda表达式  void (int,int) ---> void (int)
    f2(100);
}

// bind 包装成员函数
class MyClass
{
public:
    int add(int a, int b)
    {
        cout << "a:" << a << " b:" << b << endl;
        return a + b;
    }
};

void test5()
{
    MyClass obj;
    // 通过对象.成员函数调用
    obj.add(1,2);
    cout << "------" << endl;
    // 通过指针->成员函数调用
    MyClass * p = &obj;
    p->add(1,2);
    cout << "------" << endl;
    auto f1 = bind(&MyClass::add, obj, 10, 20);
    f1();
    cout << "----" << endl;
    // int (MyClass *,int,int) ---> int ()
    auto f2 = bind(&MyClass::add, &obj, 10, 20);
    f2();
    cout << "----" << endl;
    // 使用占位符
    auto f3 = bind(&MyClass::add, &obj, std::placeholders::_1, std::placeholders::_2);
    //  int (MyClass *,int,int) ---> int (MyClass*)

    f3(100, 200);

}


// 函数引用
void test6()
{
    int num = 1;
    int & ref = num;
    ref = 2;
    cout << ref << endl;
    cout << "--------" << endl;

    // 定义一个引用绑定到函数上
    // int add(int,int)
    // int (int,int) 函数类型
    int (&refAdd)(int,int) = add;
    // add(1,2);
    refAdd(1,2);  // 通过函数引用调用

    // 其他写法
    auto & refAdd2 = add;
    refAdd2(1,2);  // 通过函数引用调用
}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
    return 0;
}
