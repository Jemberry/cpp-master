#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/*
for_each函数:
定义于头文件 <algorithm>
template< class InputIt, class UnaryFunction >
UnaryFunction for_each( InputIt first, InputIt last, UnaryFunction f ); 
按顺序应用给定的函数对象 f 到解引用范围 [first, last) 中每个迭代器的结果

*/
void func(int num)
{
    cout << num << " ";
}

// 使用的是函数
void test1()
{
    vector<int> box { 1, 2, 3, 4, 5};
    list<int> box2 { 2,1,3,5,4};
    for_each(box.begin(), box.end(), func);
    // 把迭代器范围内的元素应用与func函数
    cout << endl;
    cout << "-----" << endl;
    for_each(box2.begin(), box2.end(), func);
    cout << endl;
}

// 函数指针
void test2()
{
    vector<int> box { 1, 2, 3, 4, 5};
    list<int> box2 { 2,1,3,5,4};
    for_each(box.begin(), box.end(), &func);
    // 把迭代器范围内的元素应用与func函数
    cout << endl;
    cout << "-----" << endl;
    for_each(box2.begin(), box2.end(), &func);
    cout << endl;
}

struct Func
{
    // operator() 重载
    void operator()(int num)
    {
        cout << num << " ";
    }
};

// 使用函数对象
void test3()
{
    vector<int> box{ 1, 2, 3, 4, 5};
    for_each(box.begin(), box.end(),Func());
}

// 使用lambda表达式
void test4()
{
    vector<int> box{ 1, 2, 3, 4, 5};
    for_each(box.begin(), box.end(), 
        [](int num)->void{
            cout << num << " ";
        });

    cout << endl;
}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}
