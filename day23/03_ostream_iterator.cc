#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>


using namespace std;

/*
输出流迭代器 ostream_iterator
写数据 *it = 100;
*/

void test1()
{
    // 创建ostream流迭代器
    ostream_iterator<int> it{ cout , " "};
    // 写数据
    *it = 1;
    ++it;
    *it = 2;
}
void test2()
{
    // 创建ostream流迭代器
    ostream_iterator<string> it{ cout , ","};
    // 写数据
    *it = "abc";
    ++it;
    *it = "hello"; // cout<< "abc" << ", " << "hello" << ", "
    cout << endl;
}

void test3()
{
    // 创建文件输出流对象
    ofstream ofs("temp.txt");
    // 创建ostream流迭代器
    ostream_iterator<string> it{ ofs , " "};
    // 写数据
    *it = "abc";
    ++it;
    *it = "hello";
    cout << endl;
    ofs.close();
}

// 一般使用std::copy 结合输出流迭代器打印容器中的数据
void test4()
{
    // vector<int> box{1,2,3,4,5};
    list<int> box{1,2,3,4,5};
    auto itFirst = box.begin();
    auto itLast = box.end();
    // 创建一个输出迭代器对象
    ostream_iterator<int> it{ cout , " "};
    // 打印容器中的数据
    std::copy(++itFirst, itLast, it);
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







