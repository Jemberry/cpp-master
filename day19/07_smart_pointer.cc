#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::auto_ptr;

/*
 * 智能指针: 
 * auto_ptr : 仅了解, 后续C++版本中弃用了
 * unique_ptr: 独占所有权
 * shared_ptr: 共享所有权
 * weak_ptr
 */

class Point
{
public:
    Point(int x, int y)
    : m_x(x)
    , m_y(y)
    {

    }
    void print()
    {
        cout << m_x << " " << m_y << endl;
    }
private:
    int m_x;
    int m_y;
};


// auto_ptr基本使用
void test1()
{
    auto_ptr<Point> ap { new Point{1,2} };
    ap->print();
    (*ap).print();
    ap.get()->print();
}

void test2()
{
    auto_ptr<Point> ap { new Point{3,4} };
    ap->print();
    cout << "-----" << endl;
    auto_ptr<Point> ap2 = ap;
    ap2->print();
    cout << "-----" << endl;
    ap->print();// error 资源已经转移个其他的智能指针
}


int main(int argc, char * argv[])
{
    /* test1(); */
    test2();
    return 0;
}

