#include <iostream>
#include <functional>
#include <vector>

using namespace std;

/*
使用std::function + std::bind实现函数式多态
*/


class Figure
{
public:
    // 定义了一种新类型 function<double()>容器 
    // 作为一种接口
    using AreaCall = function<double()>;

    // setAreaCall 初始化
    // 回调函数的注册
    void setAreaCall(AreaCall areaCall)
    {
        m_areaCall = areaCall;
    }

    // area 调用回调函数
    void handleAreaCall(){
        if(m_areaCall)
        {
            // 调用回调函数
            cout << "invoke....." << endl;
            cout << "area:" << m_areaCall() << endl;
        }
    }

    //让新类型作为数据成员
    AreaCall m_areaCall;
};

class Rectangle
{
public:
    Rectangle(double l, double w)
    : m_l(l)
    , m_w(w)
    {
    }
    double area()
    {
        cout << "Rectangle area" << endl;
        return m_l * m_w;
    }
    double m_l;
    double m_w;
};

class Circle 
{
public:
    Circle(double r)
    : m_r(r)
    {
    }
    double area()
    {
        cout << "Circle area" << endl;
        return m_r * m_r * 3.14;
    }
    double m_r;
};



void test1()
{
    Rectangle r(1,2);  // double(Reactangle*)
    Circle c(3); // double(Circle*)
    Figure figure;
    // double()  函数类型
    figure.setAreaCall(bind(&Rectangle::area, &r));
    figure.handleAreaCall();
    cout << "-------" << endl;
    figure.setAreaCall(bind(&Circle::area, &c));
    figure.handleAreaCall();
}

// 注意: lambda捕获局部变量的引用 注意生命周期的问题
vector<function<void()>> functions;
void func()
{
    // 局部变量
    double num1 = 3.14;
    int num2 = 2;
    functions.push_back(
        [&]()->void{
            cout << "num1:" << num1 << endl;
            cout << "num2:" << num2 << endl;
        }
    );
}

void test2()
{
    func();
    for(auto & f : functions)
    {
        // 调用function对象
        f();
    }
}

int main(int argc, char const *argv[])
{
    // test1();
    test2();

    return 0;
}
