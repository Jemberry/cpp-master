#include <iostream>
#include <set>
#include <list>
#include <vector>

using namespace std;

/*
关联式容器 : 底层结构红黑树
set : 无重复元素的集合 升序排序
multiset : 有重复元素的集合 升序排序
map : 存储键值对数据(key-value) key唯一 value可以重复 key升序排序
multimap : 存储键值对数据(key-value) key可以重复 value可以重复 key升序排序

*/

template<typename Container>
void print(Container &box)
{
    for(auto & e : box)
    {
        cout << e << " ";
    }
    cout << endl;
}

// 容器的构建
void test1()
{
    // 无参构造
    multiset<int> box1;
    // 初始化列表
    multiset<int> box2{1,2,3,4,5};
    // 拷贝构造
    multiset<int> box3(box2);
    // set<int> box3 = box2;
    // 迭代器
    multiset<int> box4{ box2.begin(), box2.end() };
    print(box2);
} 


// insert
void test2()
{
    multiset<int> box;
    auto it = box.insert(2);
    cout << *it << endl;
    box.insert(2);
    box.insert(1);
    box.insert(4);
    box.insert(3);
    print(box);
    cout << "----" << endl;
    list<int> box2{10,20,30};
    box.insert(box2.begin(), box2.end());
    print(box);
    cout << "----" << endl;
    box.insert({100,200});
    print(box);
}

// 查找 count / find
void test3()
{
    multiset<int> box{1,2,3,3,3,4,4,5};
    print(box);
    // count: 找到大于0, 未找到返回0
    cout << box.count(3) << endl;
    cout << box.count(6) << endl;
    cout << "---------" << endl;
    // find: 找到了返回对于位置的迭代器,没找到返回end()
    // 如果有多个重复的元素, 找到的是第一个元素的迭代器
    auto it = box.find(3);
    // auto it = box.find(6);
    if(it != box.end()){
        cout << "找到" << endl;
        cout << *it << endl;
        ++it;
        cout << *it << endl;
        ++it;
        cout << *it << endl;
        ++it;
        cout << *it << endl;
    }else{
        cout << "未找到" << endl;
    }

}


// erase删除元素
void test4()
{
    multiset<int> box{1,2,3,4,5};
    auto it = box.begin();
    ++it;
    auto it2 = box.erase(it);
    cout << *it2 << endl;
    print(box);
}

// multiset不支持下标访问
void test5()
{
    multiset<int> box{1,2,3,4,5};
    // cout << box[0] << endl; // operator[] 未定义的成员函数
    auto it =box.begin();
    cout << *it << endl;
    // *it = 10;  // error  通过迭代器进行赋值 只能进行读操作

}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    test4();
    // return 0;
}
