#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <unordered_set>

using namespace std;

/*
迭代器分类:
1.输出迭代器 output iterator  : 写操作 *it = 100
2.输入迭代器 input iterator  : 读操作 *it
3.前向迭代起 forward iterator : 只能往右移动 单向 ++it
4.双向迭代器 bidirectional iterator : 可以往右也可以往左移动 双向 ++it --it
5.随机访问迭代器 random access iterator: 上面的功能都有 it += 3 / it -= 3
*/


// 从容器中获取迭代器
// 非关联式容器:  unordered_set  前向迭代起 forward iterator
void test1()
{
    unordered_set<int> box{1,2,3,4,5};
    auto it = box.begin();
    it++;
    it++;
    // it--;   // error 只能往右移动
    cout << *it << endl;
}

// list中获取双向迭代器
void test2()
{
    list<int> box{1,2,3,4,5};
    auto it = box.begin();
    ++it;
    ++it;
    --it;
    *it = 100; // 写操作
    cout << *it << endl; // 读操作

    // it += 3;  error 只能单步移动
}

// vector中获取随机访问迭代器
void test3()
{
    vector<int> box{1,2,3,4,5};
    auto it = box.begin();
    ++it;
    ++it;
    --it;
    *it = 100; // 写操作
    cout << *it << endl; // 读操作

    it += 3;  // 可以随机访问
    cout << *it << endl;
}
int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    test3();
    return 0;
}
