#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <utility>

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
    for(auto & p : box)
    {
        cout << p.first << " = " << p.second << endl;
    }
    cout << endl;
}

template<typename K, typename V>
void print2(map<K,V> &box)
{
    for(auto & p : box)
    {
        cout << p.first << " = " << p.second << endl;
    }
    cout << endl;
}

// 容器的构建
void test1()
{
    // 无参构造
    map<int,string> box1;
    // 初始化列表
    map<int,string> box2{
        {1,"a"},
        {2,"b"},
        {3,"c"}
    };
    map<int,string> box3{
        pair<int,string>{1,"a"},
        pair<int,string>{2,"b"},
        pair<int,string>{3,"c"}
    };
    map<int,string> box4{
        make_pair(1,"a"),
        make_pair(2,"b"),
        make_pair(3,"c")
    };
    // 迭代器
    map<int,string> box5{ box2.begin(), box2.end() };
    // 拷贝构造
    map<int,string> box6(box2);
    // map<int,string> box6 = box2;
} 

// 查找操作 count / find
void test2()
{
    map<string,int> box{
        {"b",2},
        {"c",3},
        {"a",1},
        {"a",1}
    };
    print(box);
    print2(box);
    cout << "----" << endl;
    // count() : 找到了返回1 没找到返回0
    // int result = box.count("a");
    int result = box.count("d");
    cout << result << endl;

    cout << "-------" << endl;
    // find() : 找到了返回目标元素的迭代器 没找到返回end()
    auto it = box.find("a");
    if(it != box.end()){
        cout << "找到了!" << endl;
        cout << it->first << " = " << it->second << endl;
    }else{
        cout << "没找到!" << endl;
    }
}

// insert
void test3()
{
    map<string,int> box;
    // 单个数据插入
    box.insert(pair<string,int>{"a",1});
    box.insert({"b",2});
    box.insert(make_pair("zs",20));
    print(box);
    // 批量数据插入  初始化列表方式
    box.insert({
        {"ls",21},
        {"ww",20},
        {"zl",21},
    });
    print(box);
    // 或者用迭代器范围方式
    // box.insert(first, last)
}

// erase 删除
void test4()
{
    map<string,int> box;
    // 单个数据插入
    box.insert(pair<string,int>{"a",1});
    box.insert({"b",2});
    box.insert(make_pair("zs",20));
    print(box);
    auto it = box.begin();
    ++it;
    box.erase(it);
    print(box);
}

// map中可以根据[key] 获取或者修改对应的value数据
void test5()
{
    map<string,int> box;
    box.insert(pair<string,int>{"a",1});
    box.insert({"b",2});
    box.insert(make_pair("zs",20));
    box["c"] = 3;
    print(box);
    box["a"] = 100;
    cout << box["a"] << endl;
}

class Student
{
public:
    Student(int id, string name, int age)
    :m_id(id)
    ,m_name(name)
    ,m_age(age)
    {

    }

    int m_id;
    string m_name;  
    int m_age;

};
// operator<<
ostream & operator<<(ostream & os, const Student & s)
{
    os << s.m_id << " " << s.m_name << " " << s.m_age << endl;
    return os;
}

/*
针对自定义类型处理: 和set一样
1.自定义类型重载operator<
2.函数对象方式 自定义比较器 operator()
3.std::less<Student>做特化处理
*/

// 自定义比较器
struct StudentCompare
{
    // operator() 
    bool operator()(const Student & lhs, const Student & rhs) const
    {
        // 制定比较规则
        // 按照年龄升序排序
        return lhs.m_age < rhs.m_age;
    }
};

void test6()
{
    map<Student,int,StudentCompare> box;
    box.insert({Student{2,"zs",18},2});
    box.insert({Student{2,"zs",18},2});
    box.insert({Student{1,"ls",20},1});
    box.insert({Student{3,"ww",19},3});
    print(box);

}
int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();

    // return 0;
}
