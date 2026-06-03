#include <iostream>
#include <memory>

using namespace std;

/*
智能指针的误用: 一般情况下形式可能不同 但是本质是类似的
都是操作原始指针交给不同的智能指针对象进行管理
*/
class Point : public enable_shared_from_this<Point>
{
public:
    Point(int x, int y)
        : m_x(x), m_y(y)
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
    // Point *addPoint(Point *pt)
    shared_ptr<Point> addPoint(Point *pt)
    {
        m_x += pt->m_x;
        m_y += pt->m_y;
        // return this;
        // return shared_ptr<Point>{this};
        // 回共享 *this 所有权的 shared_ptr 对象 合法共享
        return shared_from_this();
    }

private:
    int m_x;
    int m_y;
};

void test5()
{
    shared_ptr<Point> sp(new Point(1,2));    
    shared_ptr<Point> sp2(new Point(3,4));

    shared_ptr<Point> sp3(sp->addPoint(sp2.get()));
    cout << sp3.use_count() << endl;
    cout << sp.use_count() << endl;
    sp3->print();
}


// shared_ptr
void test1()
{
    shared_ptr<Point> up1{new Point{1, 2}};
    shared_ptr<Point> up2{up1.get()};
    up1->print();
    up2->print();
}

// shared_ptr
// 错误示例：使用 get() 获取原始指针后，用它创建另一个 shared_ptr
// 问题：同一个原始指针被两个独立的 shared_ptr 管理，每个都认为自己拥有该对象
// 当两个智能指针生命周期结束时，会导致同一个对象被 delete 两次，引发未定义行为
void test2()
{
    // 创建第一个 shared_ptr，管理 Point 对象
    shared_ptr<Point> up1{new Point{1, 2}};

    // 错误：使用 up1.get() 获取原始指针，并以此创建第二个 shared_ptr
    // 这会导致 up1 和 up2 各自维护独立的引用计数（都为1）
    // 两个智能指针都认为自己是对象的唯一所有者
    shared_ptr<Point> up2{up1.get()};

    // 调用对象方法，此时对象还未被销毁
    up1->print();
    up2->print();

    // 函数结束时，up2 先析构，将对象 delete
    // 然后 up1 析构，再次将同一个对象 delete，导致程序崩溃
}

void test3()
{
    Point *p = new Point{1, 2};
    shared_ptr<Point> up1{p};
    shared_ptr<Point> up2{p};
    up1->print();
    up2->print();
}

void test4()
{
    Point *p = new Point{1, 2};
    shared_ptr<Point> up1{p};
    shared_ptr<Point> up2{p};
    up1->print();
    up2->print();
}
int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}