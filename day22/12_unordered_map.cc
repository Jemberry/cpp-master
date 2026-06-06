#include <iostream>
#include <unordered_set>
#include <unordered_map>

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
        cout << e.first << " " << e.second << " " << endl;
    }
    cout << endl;
}

// 容器的特点
void test1()
{
    unordered_map<string,int> box{
        {"zs", 18},
        {"zs", 18},
        {"ls", 20},
        {"ww", 19},
    };
    print(box);
    /*
    输出结果
    ww 19 
    ls 20 
    zs 18 
    数据无序  key唯一不能重复
    */
}

// 基本操作
void test2()
{
    unordered_map<string,int> box;
    // 插入元素
    box.insert({"zs", 20});
    box.insert({"zs", 20});
    box.insert({"ls", 19});
    box.insert({"ww", 18});

    // 查找
    int rusult = box.count("zs");
    // 删除
    // box.erase(box.begin());
    // ......
   
    print(box);
    cout << "-------" << endl;
    box["zs"] = 21;
    cout << box["zs"] << endl;
    box["zl"] = 22;
    cout << "------" << endl;
    print(box);

    // 基本操作和map一致
    // 针对自定义类型处理 和 unordered_set一样
}


int main(int argc, char const *argv[])
{
    // test1();
    test2();
    return 0;
}
