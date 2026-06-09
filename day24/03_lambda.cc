#include <iostream>
#include <vector>
#include <list>

using namespace std;


/*
lambda表达式:
基本语法:
[捕获列表](参数列表)opt->返回值类型
{
    // 函数体 do sth
}
捕获列表: 获取lambda表达式同一作用域内的局部变量
参数列表: 像函数的参数列表一样
opt:函数选项 一般不用
->返回值类型
函数体: lambda表达式要执行的操作

本质: 匿名的函数对象, 可以像函数一样调用
*/

void func()
{
    cout << "func" << endl;
}

void func(int num)
{
    cout << num << endl;
    cout << "func" << endl;
}

// 基本语法使用
void test1()
{
    // 无参 无返回值
    []()->void{
        cout << "lambda1" << endl;
    }(); // func();
    // 一次性的调用
    cout << "---------" << endl;
    // 有参 无返回值
    [](int num)->void{
        cout << "num = " << num << endl;
        cout << "lambda2" << endl;
    }(100);   // func(100)
    cout << "--------" << endl;
    // 有参 有返回值
    int sum = [](int a ,int b)->int{
        cout << "lambda3" << endl;
        return a + b;
    }(1,2);  // int sum = func(1,2);
    cout << sum << endl;
    cout << "-------" << endl;
    int sum2 = [](int a ,int b){
        cout << "lambda4" << endl;
        return a + b;
    }(1,2);
    cout << sum2 << endl;
    cout << "-------> " << endl;
    // 捕获列表
    int num1 = 10; // 局部变量 test1()
    int num2 = 20;

    [num1,num2]()->void{
        cout << "lambda5" << endl;
        cout << "num1 = " << num1 << endl;
        cout << "num2 = " << num2 << endl;
    }();
}

// 捕获列表规则
// & : 按引用捕获
void test2()
{
    int a = 1;
    int b = 2;
    // & : 按引用捕获
    [&]()->void{
        cout <<"a =" << a << endl;
        cout <<"b = " << b << endl;
        ++a;
        ++b;
    }();
    cout << "a = " << a << endl; // 2
    cout << "b = " << b << endl; // 3

}


// = : 按值捕获
void test3()
{
    int a = 1;
    int b = 2;
    // = : 按值捕获
    [=]()->void{
        cout <<"a =" << a << endl;
        cout <<"b = " << b << endl;
        // ++a; error 不能修改按值捕获的变量  不能修改副本的值
        // ++b;
    }();
    cout << "a = " << a << endl; // 1
    cout << "b = " << b << endl; // 2
}


void  test4()
{
    int a = 1;
    int b = 2;
    int c = 3;
    // a变量按引用捕获 其余变量按值捕获
    [=, &a]()->void{
        cout <<"a =" << a << endl;
        cout <<"b = " << b << endl;
        cout <<"c = " << c << endl;
        ++a;
        // ++b;
        // ++c;
    }();
    cout << "a = " << a << endl; // 1
    cout << "b = " << b << endl; // 2

}


void  test5()
{
    int a = 1;
    int b = 2;
    int c = 3;
    // b变量按值捕获 副本不能进行修改
    [b]()->void{
      
        cout <<"b = " << b << endl;
        // ++b;  按值捕获
    }();

    cout << "--------" << endl;
    // b变量按引用捕获 可以进行修改
    [&b]()->void{
      
        cout <<"b = " << b << endl;
        ++b;  // 可以修改引用捕获的变量
    }();

    cout << "a = " << a << endl; // 1
    cout << "b = " << b << endl; // 2

}


void  test6()
{
    int a = 1;
    int b = 2;
    int c = 3;
    // b变量按值捕获 其余的变量按引用捕获
    [&, b]()->void{
      
        cout <<"b = " << b << endl;
        // ++b;  //按值捕获
        cout << "a = " << a << endl;
        cout << "c = " << c << endl;
        ++a;
        ++c;
    }();


    cout << "a = " << a << endl; // 1
    cout << "b = " << b << endl; // 2

}


class MyClass
{
public:
    // 成员函数
    void func()
    {   
        int a = 10;
        // 局部位置
        // 捕获this指针
        // [this]()->void{
        // [=]()->void{
        [&]()->void{
            // 如果使用的是& 或者 = 默认添加this
            cout << a << endl;
            cout<< this->m_data << endl;
            this->m_data = 100;
        }();

    }

    int m_data = 1;

};

void test7()
{
    int a = 1;
    int b = 2;
    // 按值捕获所有局部变量
    [=]() mutable ->void{
        ++a; // mutable 可以修改按值捕获的变量 修改的是其副本数据
        ++b;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }();

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 如果想多次调用同一个lambda 那么可以使用auto接收
void test8()
{
    auto f = []()->void{
        cout << "lambda8" << endl;
    };
    f();
    f();
    f();
    cout << "------" << endl;
    auto f1 = [](const int & num)->void{
        cout << "num = " << num << endl;
    };
    f1(100);
    f1(200);
    f1(300);
}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    // test7();
    test8();
    return 0;
}
