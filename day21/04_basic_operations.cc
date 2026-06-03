#include <iostream>
#include <vector>
#include <list>
#include <deque>


using namespace std;

void print(vector<int> &box)
{
    for(auto & e : box)
    {
        cout << e << " ";
    }
    cout << endl;
}

//定义一个函数模板
template<typename Container>
void print(Container &box)
{
    for(auto & e : box)
    {
        cout << e << " ";
    }
    cout << endl;
}


// vector初始化
void test1()
{
    // 无参构造
    vector<int> box1;
    // 初始化列表
    vector<int> box2 {1,2,3,4,5};
    // 拷贝构造
    vector<int> box3{box2};
    // vector<int> box3 = box2;
    // 迭代器范围
    vector<int> box4{box2.begin(), box2.end()};
    // cout个value
    vector<int> box5(3,100);
    print(box2);
}

// list初始化
void test2()
{
    // 无参构造
    list<int> box1;
    // 初始化列表
    list<int> box2 {1,2,3,4,5};
    // 拷贝构造
    list<int> box3{box2};
    // list<int> box3 = box2;
    // 迭代器范围
    list<int> box4{box2.begin(), box2.end()};
    // cout个value
    list<int> box5(3,100);
    print(box2);
}


// deque初始化
void test3()
{
    // 无参构造
    deque<int> box1;
    // 初始化列表
    deque<int> box2 {1,2,3,4,5};
    // 拷贝构造
    deque<int> box3{box2};
    // deque<int> box3 = box2;
    // 迭代器范围
    deque<int> box4{box2.begin(), box2.end()};
    // cout个value
    deque<int> box5(3,100);
    print(box2);
}

// 容器遍历
void test4()
{
    cout << "------vector-------" << endl;

    vector<int> box1 {1,2,3,4,5};
    // fori 下标 进行遍历
    for(int i = 0; i < box1.size(); ++i)
    {
        cout << box1[i] << " ";
    }    
    cout << endl;

    // 迭代器遍历
    for(auto it = box1.begin(); it != box1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    // foreach遍历
    for(auto & e : box1)
    {
        cout << e << " ";
    }
    cout << endl;

    cout << "------list-------" << endl;
    list<int> box2 {1,2,3,4,5};
    // fori 下标 进行遍历
    // for(int i = 0; i < box2.size(); ++i)
    // {
    //     cout << box2[i] << " "; //list不支持operator[]
    // }    
    // cout << endl;

    // 迭代器遍历
    for(auto it = box2.begin(); it != box2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    // foreach遍历
    for(auto & e : box2)
    {
        cout << e << " ";
    }
    cout << endl;

    cout << "------deque-------" << endl;
    deque<int> box3 {1,2,3,4,5};
    // fori 下标 进行遍历
    for(int i = 0; i < box3.size(); ++i)
    {
        cout << box3[i] << " ";
    }    
    cout << endl;

    // 迭代器遍历
    for(auto it = box3.begin(); it != box3.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    // foreach遍历
    for(auto & e : box3)
    {
        cout << e << " ";
    }
    cout << endl;
}

// vector: push_back() /  pop_back()
void  test5()
{
    vector<int> box{1,2,3};
    print(box);
    box.push_back(4);
    box.push_back(5);
    print(box);
    box.pop_back();
    print(box);
}

// list: push_back() /  pop_back()
void  test6()
{
    list<int> box{1,2,3};
    print(box);
    box.push_back(4);
    box.push_back(5);
    print(box);
    box.pop_back();
    print(box);
}

// deque: push_back() /  pop_back()
void  test7()
{
    deque<int> box{1,2,3};
    print(box);
    box.push_back(4);
    box.push_back(5);
    print(box);
    box.pop_back();
    print(box);
}

// list: push_front() /  pop_front() 头部插入和删除元素
void test8()
{
    list<int> box{1,2,3};
    print(box);
    box.push_front(4);
    box.push_front(5);
    print(box);
    box.pop_front();
    print(box);
}

// deque: push_front() /  pop_front() 头部插入和删除元素
void test9()
{
    deque<int> box{1,2,3};
    print(box);
    box.push_front(4);
    box.push_front(5);
    print(box);
    box.pop_front();
    print(box);
}

// vector 不支持push_front() /  pop_front() 不能从头进行操作
void test10()
{
    vector<int> box;
//     box.push_front(1);
//     box.pop_front();
}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    test9();
    return 0;
}
