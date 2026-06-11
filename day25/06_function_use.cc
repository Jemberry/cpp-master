#include <iostream>
#include <functional>

using namespace std;

/*
使用std::function + std::bind实现函数式多态
*/

// 父类 抽象类
class Figure
{
public:
    virtual double area() = 0;
};

class Rectangle : public Figure
{
public:
    Rectangle(double l, double w)
    : m_l(l)
    , m_w(w)
    {
    }
    double area() override
    {
        cout << "Rectangle area" << endl;
        return m_l * m_w;
    }
    double m_l;
    double m_w;
};

class Circle : public Figure
{
public:
    Circle(double r)
    : m_r(r)
    {
    }
    double area() override
    {
        cout << "Circle area" << endl;
        return m_r * m_r * 3.14;
    }
    double m_r;
};



void test1()
{
    Rectangle r(1,2);
    Circle c(3);
    // 继承式多态
    Figure * p = &r;
    cout << p->area() << endl;
    p = &c;
    cout << p->area() << endl;
}

void test2()
{
    Rectangle r(1,2);
    Circle c(3);
    // 函数式多态
    std::function<double()> f;
    // double(Circle*) 函数类型
    // bind --->double() 函数类型
    f = bind(&Circle::area, &c);
    cout << f() << endl;
    cout << "-----" << endl;
    f = bind(&Rectangle::area, &r);
    cout << f() << endl;
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    return 0;
}
