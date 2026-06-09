#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;


/*
迭代器适配器:
1.back_insert_iterator : 尾部插入的迭代器  底层使用容器的push_back
2.front_insert_iterator: 头部插入的迭代器  底层使用容器的push_front 
3.insert_iterator: 中间位置插入的迭代器  底层使用容器的insert
以上3种都是类型

注意!!!使用时要确保容器底层是否有上述这些函数,push_back,push_front,insert

back_inserter(): 创建一个back_insert_iterator
front_inserter(): 创建一个front_insert_iterator
inserter(): 创建一个 insert_iterator
以上3个是函数, 返回对应的迭代器

*/

// 把一个容器中的元素复制到另一个空容器中
// 尾部插入
void test1()
{
    vector<int> box1{1,2,3,4,5};
    vector<int> box2;
    // 结合copy函数, 结合迭代器适配器
    // 尾插
    back_insert_iterator<vector<int>> it{ box2};
    std::copy(box1.begin(), box1.end(),it);
    // 打印box2
    std::copy(box2.begin(), box2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}


void test2()
{
    vector<int> box1{1,2,3,4,5};
    vector<int> box2;
    // 结合copy函数, 结合迭代器适配器
    // 尾插
    // 使用back_inserter函数简写
    std::copy(box1.begin(), box1.end(),back_inserter(box2));
    // 打印box2
    std::copy(box2.begin(), box2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

// 头部插入 
void test3()
{
    vector<int> box1{1,2,3,4,5};
    list<int> box2;
    // 结合copy函数, 结合迭代器适配器
    // 头部插
    front_insert_iterator<list<int>> it{ box2};
    std::copy(box1.begin(), box1.end(),it);
    // 打印box2
    std::copy(box2.begin(), box2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}


// 头部插入 
void test4()
{
    vector<int> box1{1,2,3,4,5};
    list<int> box2;
    // 结合copy函数, 结合迭代器适配器
    // 头部插
 
    std::copy(box1.begin(), box1.end(),front_inserter(box2));
    // 打印box2
    std::copy(box2.begin(), box2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

// 中间插入  底层使用的是insert函数
void test5()
{
    vector<int> box1{1,2,3,4,5};
    list<int> box2{6, 7, 8};
    // 结合copy函数, 结合迭代器适配器
    // 中间插 需要指定插入的位置
    auto it = box2.begin();
    ++it;
 
    std::copy(box1.begin(), box1.end(),inserter(box2, it));
    // 打印box2
    std::copy(box2.begin(), box2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

// 逆向迭代器
void test6()
{
    vector<int> box1{1,2,3,4,5};
    // 正着遍历
    // for(auto it  = box1.begin() ; it != box1.end() ; ++it)
    // auto it = box1.rbegin();
    vector<int>::reverse_iterator it = box1.rbegin();
    cout << *it << endl;
    ++it; // 逻辑的+ 实际上是向左移动
    cout << *it << endl;
}

void test7()
{
    vector<int> box1{1,2,3,4,5};
    // 倒着遍历
    for(auto it  = box1.rbegin() ; it != box1.rend() ; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    test7();
    return 0;
}
