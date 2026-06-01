#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

/*
 * 循环引用问题
 *
 * 通过使用weak_ptr ---> 解决shared_ptr循环引用问题
 *
 */

class Child;

class Parent
{
public:
    /* shared_ptr<Child> m_spChild; */
    weak_ptr<Child> m_spChild;// 不会使引用计数器+1
};

class Child
{
public:
    shared_ptr<Parent> m_spParent;
};

void test1()
{
    shared_ptr<Parent> parentPtr{new Parent{}};
    shared_ptr<Child> childPtr{ new Child{} };
    // 获取引用计数
    cout << "ParentPtr count:" << parentPtr.use_count() << endl;
    cout << "childPtr count:" << childPtr.use_count() << endl;
    cout << "-----" << endl;
    // 进行赋值
    parentPtr->m_spChild = childPtr;
    childPtr->m_spParent = parentPtr;
    cout << "ParentPtr count:" << parentPtr.use_count() << endl;
    cout << "childPtr count:" << childPtr.use_count() << endl;
}

int main(int argc, char * argv[])
{
    test1();
    return 0;
}

