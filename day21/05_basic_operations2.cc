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

// insert操作
void test1()
{
    vector<int> box{1,2,3,4,5};
    cout <<"size=" << box.size() << endl;
    cout << "capacity=" << box.capacity() << endl;
    print(box);
    // 给定位置 插入单个元素
    auto it =box.begin();
    ++it;
    // box.insert(it, 100); 可能会有迭代器失效的问题 扩容
    it = box.insert(it, 100); // 更新迭代器
    cout <<"size=" << box.size() << endl;
    cout << "capacity=" << box.capacity() << endl;
    print(box);
    cout << "*it=" << *it << endl;
    // 给定位置 插入多个元素
    it = box.insert(it, 2, 200); // 更新迭代器
    print(box);
    cout << "*it=" << *it << endl;
    ++it;
    cout << "*it=" << *it << endl;
    ++it;
    cout << "*it=" << *it << endl;

    auto it2 = box.begin();
    ++it2;
    // 给定位置, 用初始化列表插入
    it2 = box.insert(it2, {1000,2000});
    print(box);
    cout << "*it2=" << *it2 << endl;
    // 插入迭代器范围
    vector<int> box2{10,20,30};
    it2 = box.insert(it2, box2.begin(), box2.end());
    print(box);
}

// list: insert  没有更新迭代器
void test2()
{
    list<int> box{1,2,3,4,5};
    print(box);
    auto it = box.begin();
    ++it;
    cout << "*it=" << *it << endl;
    box.insert(it,10);
    print(box);
    cout << "*it=" << *it << endl;
    cout << "------" << endl;
    box.insert(it, 2,200);
    print(box);
    cout << "*it=" << *it << endl;

}

// list: insert  更新迭代器
void test3()
{
    list<int> box{1,2,3,4,5};
    print(box);
    auto it = box.begin();
    ++it;
    cout << "*it=" << *it << endl;
    it = box.insert(it,10); // 更新迭代器
    print(box);
    cout << "*it=" << *it << endl;
    cout << "------" << endl;
    it = box.insert(it, 2,200);// 更新迭代器
    print(box);
    cout << "*it=" << *it << endl;

}

// deque: insert  不更新迭代器
void test4()
{
    deque<int> box {1,2,3,4,5};
    print(box);
    auto it = box.begin();
    ++it;
    cout << "*it=" << *it << endl;
    box.insert(it,10);
    print(box);
    cout << "*it=" << *it << endl;
    box.insert(it,2,200);
    print(box);
    cout << "*it=" << *it << endl;
    box.insert(it,300);
    print(box);
    cout << "*it=" << *it << endl;
}


// deque: insert  更新迭代器
void test5()
{
    deque<int> box {1,2,3,4,5};
    print(box);
    auto it = box.begin();
    ++it;
    cout << "*it=" << *it << endl;
    it = box.insert(it,10);
    print(box);
    cout << "*it=" << *it << endl;
    it = box.insert(it,2,200);
    print(box);
    cout << "*it=" << *it << endl;
    it = box.insert(it,300);
    print(box);
    cout << "*it=" << *it << endl;
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
