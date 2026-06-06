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

/*
关联式容器针对自定义类型进行处理
1. 自定义类型需要重载operator< 提供一个比较规则 为了满足set的有序的特点
2. 函数对象 重载operator() 自定义比较器
3. 针对std::less做特化处理
*/

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

// 方式三: 对std::less做特化处理
namespace std
{
    template<>
    struct less<Student>  // 针对Student类型进行特殊处理
    {
        bool operator()(const Student & lhs, const Student & rhs) const
        {
            // 给定比较规则 按照学号升序排序
            return lhs.m_id < rhs.m_id;
        }
    };



}


void test1()
{
    set<Student> box;   // 这里Compare用的还是默认值 std::less
    // 通用模板不能处理Student类型, 才使用特化
    box.insert(Student{2,"zs",18});
    box.insert(Student{2,"zs",18});
    box.insert(Student{1,"ls",20});
    box.insert(Student{3,"ww",19});
    print(box);
} 


int main(int argc, char const *argv[])
{
    test1();

    return 0;
}
