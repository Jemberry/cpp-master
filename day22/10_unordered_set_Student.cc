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

class Student
{
public:
    Student(int id, string name)
    :m_id(id)
    ,m_name(name)
    {

    }

    // 计算哈希值
    size_t studentHash()  const
    {
       size_t h1 = std::hash<int>()(m_id);
       size_t h2 = std::hash<string>()(m_name);
       return h1 ^ (h2 << 1);
    }

    // 提供一个重载的==运算符
    bool operator==(const Student & rhs) const
    {
        return this->m_id == rhs.m_id && this->m_name == rhs.m_name;
    }

    int m_id;
    string m_name;  

};

// operator << 重载
ostream & operator<<(ostream & os, const Student & s)
{
    os << "Student(id: " << s.m_id << ", name: " << s.m_name << ")";
    os << endl;
    return os;
}



/*
针对自定义类型的处理:
1.函数对象
2.std::hash, std::equal_to做 Student类型的特化
*/

// 方式一: 自定义函数对象 获取哈西值  判断对象是否相等
struct StudentHash
{
    // operator() 重载
    size_t operator()(const Student & s) const
    {
        return s.studentHash();
    }
};

struct StudentEqual
{
    // operator() 重载
    bool operator()(const Student & lhs, const Student & rhs) const
    {
        // return lhs == rhs;
        return lhs.operator==(rhs);
    }
};


void test1()
{
    unordered_set<Student, StudentHash, StudentEqual> box{
        Student{1, "zs"},
        Student{1, "zs"},
        Student{2, "ls"},
        Student{3, "ww"}
    };
    print(box);
}

// 方式二: 特化处理
namespace std
{
    // std::Hash
    template <>
    struct hash<Student>
    {
        // operator() 重载
        size_t operator()(const Student & s) const
        {
            return s.studentHash();
        }
    };
    
    // std::equal_to
    template <>
    struct equal_to<Student>
    {
        // operator() 重载
        bool operator()(const Student & s1, const Student & s2) const
        {
            return s1 == s2;
        }
    };

}

void test2()
{
    unordered_set<Student> box{
        Student{1, "zs"},
        Student{1, "zs"},
        Student{2, "ls"},
        Student{3, "ww"}
    };
    print(box);
}

int main(int argc, char const *argv[])
{
    // test1();
    test2();
    return 0;
}
