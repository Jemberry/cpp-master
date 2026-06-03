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

// list erase操作 : 没有更新迭代器 失效了...
void test1()
{
    list<int> box{1,2,3,4,5,6,7};
    print(box);
    auto it = box.begin();
    ++it;
    ++it;
    box.erase(it);
    // 此时这个迭代器已经失效了 it指向的是被删掉的那个3
    // 下面的代码都是未定义行为
    print(box);
    cout << "*it=" << *it << endl;
    box.insert(it, 100);
    print(box);
    cout << "*it=" << *it << endl;
}


// list erase操作 更新迭代器
void test2()
{
    list<int> box{1,2,3,4,5,6,7};
    print(box);
    auto it = box.begin();
    ++it;
    ++it;
    it = box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;
    auto itBegin = box.begin();
    auto itEnd = box.end();
    --itEnd;
    --itEnd;
    auto it2 = box.erase(itBegin, itEnd);
    print(box);
    cout << "*it2=" << *it2 << endl;
}

// deque erase操作 : 没有更新迭代器 
void test3()
{
    deque<int> box {1,2,3,4,5,6,7};
    print(box);
    auto it = box.begin();
    ++it;
    ++it;
    cout << "*it=" << *it << endl;

    box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;

    box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;
}

// deque erase操作 : 更新迭代器 
void test4()
{
    deque<int> box {1,2,3,4,5,6,7};
    print(box);
    auto it = box.begin();
    ++it;
    ++it;
    cout << "*it=" << *it << endl;

    it =box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;

    it = box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;
}

// list: erase操作 : 没有更新迭代器 
void test5()
{
    vector<int> box {1,2,3,4,5,6,7};
    print(box);
    auto it = box.begin();
    ++it;
    ++it;
    cout << "*it=" << *it << endl;
    box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;
    box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;
    box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;
}


// list: erase操作 : 更新迭代器 
void test6()
{
    vector<int> box {1,2,3,4,5,6,7};
    print(box);
    auto it = box.begin();
    ++it;
    ++it;
    cout << "*it=" << *it << endl;
    it = box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;
    it =box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;
    it = box.erase(it);
    print(box);
    cout << "*it=" << *it << endl;
}

// 删除重复的3 
void test7()
{
    vector<int> box {1,2,3,3,3,3,4,5};
    print(box);
    // 迭代器方式遍历
    for(auto it = box.begin(); it != box.end();) // for里面不要加++it
    {
        if(*it == 3)
        {
            // box.erase(it);
            it = box.erase(it); // 更新一下迭代器
        }else{
            ++it;
        }
    }
    print(box);
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
