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

using namespace std;
/*
容器适配器:
1.stack
2.queue
3.priority_queue
*/

// stack
void test1()
{
    // 默认底层使用的是deque
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // 遍历结束后, 容器为空
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << " ----" << endl;
    // 此时stack为空
    // cout << s.top() << endl;
}

// stack
void test2()
{
    // 指定底层实现为vector
    stack<int, vector<int>> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // 遍历结束后, 容器为空
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

// stack
void test3()
{
    // 指定底层实现为list
    stack<int, list<int>> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // 遍历结束后, 容器为空
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}


// queue
void test4()
{
    // 默认底层使用的是deque
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // 1 2  3  4
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

}

// queue
void test5()
{
    // 修改底层实现为vector---->error : vector 中没有pop_front函数
    // queue<int, vector<int>> q; // error
    queue<int, list<int>> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // 1 2  3  4
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

}


// priority_queue
void test6()
{
    // 默认底层使用的是vector
    priority_queue<int> q;
    q.push(2);
    q.push(1);
    q.push(4);
    q.push(3);
    // 2 1 4 3
  
    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }
    // 4 3 2 1

}


// priority_queue
void test7()
{
    // 修改底层实现为deque, 注意不能为list:list中的函数满足,但是迭代器类型不满足
    priority_queue<int, deque<int>, std::greater<int>> q;
    q.push(2);
    q.push(1);
    q.push(4);
    q.push(3);
    // 2 1 4 3
  
    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }
    // 1 2 3 4

}
int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test4();
    // test5();
    // test6();
    test7();
    return 0;
}
