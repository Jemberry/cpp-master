#include <iostream>


using namespace std;

/*

万能引用
void func2(T && t) : ---> T && t 万能引用
既可以接收左值 又可以接收右值

引用折叠规则:
1. T &  &
2. T && &
3. T & &&
4. T && &&
只要有左值引用参与 ----> 折叠为左值引用

*/

template <typename T>
void func(T & t) 
{
    cout << "func(T & t)" << endl;
}

template <typename T>
void func2(T && t)
{
    cout << "func2(T && t)" << endl;
}


void test1()
{
    int num = 1;  // 左值
    func(num); // T = int & ---> int & & ---> int &
    // 1为右值
    // func(1); error T = int &&---> int && &--->int &
    cout << "------" << endl;
    func2(num); // T = int &----> int & &&----> int &
    func2(1);  // T = int &&---> int && &&---> int &&
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
