#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

template<typename Container>
void print(Container &box)
{
    for(auto & e : box)
    {
        cout << e << " ";
    }
    cout << endl;
}

// size()  clear()
void test1()
{
    list<int> box {1,2,3,4,5};
    print(box);
    cout << box.size() << endl;
    box.clear();
    print(box);
    cout << box.size() << endl;
    
}

// swap() 内容换
void test2()
{
    // list<int> box1 {1,2,3,4,5};
    // list<int> box2 {6,7,8};
    vector<int> box1 {1,2,3,4,5};
    vector<int> box2 {6,7,8};
    print(box1);
    print(box2);
    cout << "-----swap---" << endl;
    box1.swap(box2);
    print(box1);
    print(box2);

}

// resize() 更改元素个数
void test3()
{
    list<int> box{1,2,3,4,5};
    cout << box.size() << endl;
    print(box);
    // box.resize(3);
    box.resize(10);
    cout << box.size() << endl;
    print(box);
}

// front()  / back()  获取容器的第一个元素 最后一个元素
void test4()
{
    list<int> box{1,2,3,4,5};
    cout << box.front() << endl;
    cout << box.back() << endl;

}


// shrink_to_fit()  缩减容器的容量
void test5()
{
    vector<int> box{1,2,3,4,5};
    cout << box.size() << endl;
    cout << box.capacity() << endl;
    box.reserve(10);
    cout << box.size() << endl;
    cout << box.capacity() << endl;
    cout << "--------" << endl;
    //shirk_to_fit 回收多余空间
    box.shrink_to_fit();
    cout << box.size() << endl;
    cout << box.capacity() << endl;
}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}
