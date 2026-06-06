#include <iostream>
#include <unordered_set>

using namespace std;

/*
无序关联式容器: 底层使用的是哈希表
unordered_set 无序集合容器  元素是唯一的
unordered_multiset 无序多集合容器, 允许元素重复

unordered_map 无序映射容器  key是唯一的
unordered_multimap 无序多映射容器, 允许key重复

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
    unordered_multiset<int> box {3,3, 1,2,4,5};
    print(box); // 5 4 2 1 3 3 
    // 存储的元素无序  元素能重复
}

// 基本操作
void test2()
{
    unordered_multiset<int> box;
    // 插入元素
    box.insert(1);
    box.insert(2);
    box.insert(3);
    // 查找
    int rusult = box.count(3);
    // 删除
    box.erase(box.begin());
    // ......
    // 基本操作和unordered_set一致
    // 针对自定义类型处理和unordered_set一致


}


int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
