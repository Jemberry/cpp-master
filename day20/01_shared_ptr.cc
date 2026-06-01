#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;
/*
 * shared_ptr: 共享所有权的智能指针
 *
 * 合法的共享:
 * 可以进行赋值,复制操作--->进行共享所有权
 *
 * 非法的共享:
 * 直接操作原始指针 , 交给另一个智能指针进行管理
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

// 创建shared_ptr对象
void test1()
{
    shared_ptr<Point> sp { new Point{1,2} };
    shared_ptr<Point> sp2 = std::make_shared<Point>(3,4);

}


// 基本使用
void test2()
{

    shared_ptr<Point> sp { new Point{1,2} };
    sp->print();
    (*sp).print();
    sp.get()->print();
}

// 测试共享所有权
// 合法的共享
void test3()
{
    shared_ptr<Point> sp1 { new Point{1,2} };
    cout << "sp1:count :" << sp1.use_count()<< endl;
    shared_ptr<Point> sp2 = sp1; // 拷贝构造
    sp1->print();
    sp2->print();
    cout << "-----" << endl;
    // 获取引用计数 use_count()
    cout << "sp1:count :" << sp1.use_count()<< endl;
    cout << "sp2:count :" << sp2.use_count()<< endl;
    cout << "------" << endl;

    shared_ptr<Point> sp3 { new Point{3,4} };
    sp3 = sp1; // 赋值运算符函数

    cout << "sp1:count :" << sp1.use_count()<< endl;
    cout << "sp2:count :" << sp2.use_count()<< endl;
    cout << "sp3:count :" << sp3.use_count()<< endl;


}

// 非法的共享
void test4()
{
    // 原始指针暴露出来
    Point * p = new Point{1,2};
    shared_ptr<Point> sp1 { p };
    sp1->print();
    cout << "-----" << endl;
    // 把原始指针交给另一个指针指针管理
    shared_ptr<Point> sp2 { p };
    sp2->print();
    cout << "-----" << endl;
    cout << "sp1 count:" << sp1.use_count() << endl;
    cout << "sp2 count:" << sp2.use_count() << endl;

}

// 其他形式的非法共享 
void test5()
{
    shared_ptr<Point> sp1 { new Point{1,2} };
    shared_ptr<Point> sp2 { sp1.get() };
    sp1->print();
    sp2->print();
    cout << "sp1 count:" << sp1.use_count() << endl;
    cout << "sp2 count:" << sp2.use_count() << endl;
}

void test6()
{
    vector<shared_ptr<Point>> v;
    shared_ptr<Point> sp1 { new Point{1,2} };
    shared_ptr<Point> sp2 { new Point{3,4} };
    shared_ptr<Point> sp3 { new Point{5,6} };
    v.push_back(sp1);
    v.push_back(sp2);
    v.push_back(sp3);
    v[0]->print();

}

int main(int argc, char * argv[])
{
    /* test1(); */
    /* test2(); */
    /* test3(); */
    /* test4(); */
    /* test5(); */
    test6();
    return 0;
}

