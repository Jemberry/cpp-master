#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <functional>
#include <algorithm>
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
    box.sort(); // 默认升序排序
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
    // // operator< 成员函数  为了sort()排序需要
    // bool operator<(const Student & rhs) const
    // {
    //     // 制定比较规则, 按照什么进行排序
    //     // 按照id升序排序
    //     // return this->m_id < rhs.m_id;
    //     // 按照年龄升序排序
    //     // return this->m_age < rhs.m_age;
    //     // 按照年龄降序排序
    //     return   rhs.m_age < this->m_age;
    // }
    int m_id;
    string m_name;  
    int m_age;
};

// operator<  为了sort()排序需要
bool operator<(const Student & lhs, const Student & rhs)
{
    return lhs.m_id < rhs.m_id;
}

// operator<<   为了cout << Student
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
    cout << "-----sort-----" << endl;
    box.sort();
    print(box);
}

// 自定义比较器
struct StudentCompare
{
    // operator()  为了sort()排序需要
    bool operator()(const Student & lhs, const Student & rhs)
    {
        // 制定比较规则
        // 按照年龄升序排序
        return lhs.m_age < rhs.m_age;
    }
};

void test3()
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
    cout << "-----sort-----" << endl;
    box.sort(StudentCompare()); // 里面是函数对象
    print(box);
}

void test4()
{
    list<int> box{ 3,1,2,5,4};
    print(box);
    // box.sort(); vector里没有sort成员函数
    // box.sort(std::less<int>()); // 升序 使用的是带Compare的sort()函数 std::less<int>() C++中提供函数对象
    box.sort(std::greater<int>()); // 降序 使用的是带Compare的sort()函数 std::greater<int>() C++中提供函数对象
    print(box);
}

// 如果不是list容器,怎么排序
void test5()
{
    // vector<int> box{ 3,1,2,5,4};
    deque<int> box{ 3,1,2,5,4};
    print(box);
    cout << "------" << endl;
    // box.sort(); vector或deque容器没有sort成员函数
    // 可以使用算法库中的sort函数进行排序
    // 参数是迭代器区间 默认升序
    std::sort(box.begin(), box.end()); 
    print(box);
}

// reverse : 逆序
void test6()
{
    list<int> box{1,2,3,4,5};
    print(box);
    cout << "------" << endl;
    box.reverse();
    print(box);


}

// unique: 删除连续的重复的元素  使用前提 数据有序(可以先sort)
void test7()
{
    list<int> box{1,2,2,2,3,3,3,4,5};
    // list<int> box{1,2,2, 4, 5, 2,3,3,3,4,5,3};
    print(box);
    cout << "------" << endl;
    box.unique();
    print(box);

}

// merge: 合并两个有序的list容器
void test8()
{   
    list<int> box1{1,3,5};
    list<int> box2{2,4,6};
    box1.merge(box2);
    print(box1);
    cout << "-----" << endl;
    print(box2);  // 没有数据了 相当于把元素移动到了box1

}


// remove 
void test9()
{   
    list<int> box{1,2,3,3,3,4,5,3,6};
    print(box);
    // 删除容器中所有的3
    box.remove(3);
    print(box);
}

bool overThree(int n)
{
    return n > 3;
}

// remove_if 带条件的删除
// remove_if(一元谓词) : 一元函数, 函数的返回值必须是布尔类型
void test10()
{
    list<int> box{1,2,3,4,5,6};
    print(box);
    box.remove_if(overThree);
    print(box);
}

// splice : 元素转移
void test11()
{
    list<int> box1{1,2,3,4};
    list<int> box2{5, 6, 7};
    print(box1);
    print(box2);
    auto it = box1.begin();
    ++it;
    box1.splice(it, box2);
    print(box1);
    print(box2);
    cout << "-----" << endl;
    list<int> box3{1,2,3,4};
    list<int> box4{5, 6, 7};
    print(box3);
    print(box4);
    auto it2 = box3.begin();
    auto it3 = box4.begin();
    ++it3;
    box3.splice(it2, box4, it3);
    print(box3);
    print(box4);
    cout << "-----" << endl;
    list<int> box5{1,2,3,4};
    list<int> box6{5, 6, 7};
    print(box5);
    print(box6);
    box5.splice(box5.end(), box6, box6.begin(), box6.end());
    print(box5);
    print(box6);
    cout << "-----" << endl;

    list<int> box{1,2,3,4,5,6,7};
    print(box);
    box.splice(box.begin(), box, --box.end());
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
    // test7();
    // test8();
    // test9();
    // test10();
    test11();

    return 0;
}
