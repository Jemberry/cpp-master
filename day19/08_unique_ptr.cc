#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;
/*
 * unique_ptr智能指针: 独占资源所有权
 * 不允许复制相关的操作: 拷贝构造 赋值运算符函数删除了
 * 注意:
 * unique_ptr作为容器中的元素
 */

class Point
{
public:
    Point(int x, int y)
    : m_x(x)
    , m_y(y)
    {

    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }
    void print()
    {
        cout << m_x << " " << m_y << endl;
    }
private:
    int m_x;
    int m_y;
};

// 基本使用
void test1()
{
    // 把资源交给智能指针管理
    // 利用构造函数创建的智能指针对象
    unique_ptr<Point> up { new Point{1,2} };
    up->print();
    (*up).print();
    up.get()->print();
}

// 测试 独占所有权
void test2()
{
    unique_ptr<Point> up { new Point{1,2} };
    // 测试拷贝构造  deleted 被删除了 不允许复制
    /* unique_ptr<Point> up2 = up; */

    unique_ptr<Point> up3 { new Point{3,4} };
    // 测试赋值  不允许赋值操作
    /* up3 = up; */
}

// 作为容器的元素
void test3()
{
    vector<unique_ptr<Point>> v;
    unique_ptr<Point> up1 { new Point{1,1} };
    unique_ptr<Point> up2 { new Point{2,2}};
    unique_ptr<Point> up3 { new Point{3,3} };
    up1->print();
    cout << "------" << endl;
    // 把元素放入到vector中 直接放左值对象会3报错
    // push_back() 传参会调用拷贝构造 但是这里被删除了
    /* v.push_back(up1); */
    /* v.push_back(up2); */
    /* v.push_back(up3); */
    // 左值--->右值 --> 移动构造
    v.push_back(std::move(up1)); // up1,up2,up3中的资源被转移了
    v.push_back(std::move(up2));
    v.push_back(std::move(up3));
    v[0]->print();

    cout << "-----" << endl;

    /* up1->print(); // error up1已经不管理该资源了 */
}

void test4()
{

    // up1管理的资源是个 Point {1,1}
    unique_ptr<Point> up1 { new Point{1,1} };
    up1->print();
    // reset()替换被管理的对象
    up1.reset(new Point{3,4});
    up1->print();

}

void test5()
{
    /* unique_ptr<Point> up { new Point{1,2} }; */
    // 利用make_unique函数创建智能指针对象
    unique_ptr<Point> up = std::make_unique<Point>(1,2);
    up->print(); }

int main(int argc, char * argv[])
{
    /* test1(); */
    /* test3(); */
    /* test4(); */
    test5();
    return 0;
}

