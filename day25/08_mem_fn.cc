#include <iostream>
#include <functional>
#include <vector>

using namespace std;

/*
std::mem_fn ----> 包装成员函数指针 转换成一个函数对象
可以像函数一样调用
*/

class Number
{
public:
    Number(int data = 0) : m_data(data) {}
    // 成员函数
    void print()
    {
        cout << "m_data:" << m_data << endl;
    }
    // 一元谓词
    bool isEven()
    {
        return m_data % 2 == 0;
    }
    int m_data;
};

void test1()
{

    Number obj;
    // 成员函数指针
    void (Number::*f)() = &Number::print;
    (obj.*f)();  // obj.print()
    (&obj->*f)(); // 指针->print()

    // void print()
    // void (Number*) 函数类型
    // mem_fn: 成员函数指针---->函数对象
    auto f1 = std::mem_fn(&Number::print);
    f1(obj);
    f1(&obj);

}

void test2()
{
    vector<Number> box;
    for(int i = 0; i<10; ++i)
    {
        box.push_back(Number{i});
    }

    // 使用for_each遍历, 调用每个Number对象的成员函数
    // void(Number*)
    // void(Number&)
    // std::for_each(box.begin(), box.end(), &Number::print);
    // std::for_each(box.begin(), box.end(), bind(&Number::print, Number{}));
    // std::for_each(box.begin(), box.end(), bind(&Number::print, std::placeholders::_1));
    std::for_each(box.begin(), box.end(), std::mem_fn(&Number::print));
    // 每个对象调用print成员函数
}

void test3()
{
    vector<Number> box;
    for(int i = 0; i<10; ++i)
    {
        box.push_back(Number{i});
    }


    std::for_each(box.begin(), box.end(), std::mem_fn(&Number::print));
    cout << "---------" << endl;
    // 删除所有偶数的Number对象
    auto it = remove_if(box.begin(), box.end(), mem_fn(&Number::isEven));
    box.erase(it,box.end());
    std::for_each(box.begin(), box.end(), std::mem_fn(&Number::print));

}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    test3();
    return 0;
}

