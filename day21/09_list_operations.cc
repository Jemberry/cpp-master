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

// list中特有的操作 
// sort() 排序   内置类型直接用 默认升序排序
void test1()
{
    list<int> box{ 3,1,2,5,4};
    print(box);
    // box.sort(); vector里没有sort成员函数
    box.sort();
    print(box);
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

// 针对自定义类型进行比较排序 sort()
void test2()
{
    Student s1(2,"张三",19);
    Student s2(1,"李四",21);
    Student s3(3,"王五",20);
    list<Student> box{
        s1,
        s2,
        s3,
    };
    print(box);
    box.sort();
    print(box);
}

int main(int argc, char const *argv[])
{
    // test1();
    test2();

    return 0;
}
