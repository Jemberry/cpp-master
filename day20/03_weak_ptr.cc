#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

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


// weak_ptr基本使用
void test1()
{
    shared_ptr<Point> sp{new Point{1,2}};
    // weak_ptr创建, 接收一个shared_ptr
    // 一般配合shared_ptr使用
    weak_ptr<Point> wp = sp;
    cout << sp.use_count() << endl;
    cout << wp.use_count() << endl;
    cout << "------" << endl;
    // 不能直接通过weak_ptr访问资源
    /* wp->print();//error */

    // 只能把weak_ptr---->shared_ptr才能访问资源
    // 使用lock()函数
    weak_ptr<Point> wp2;
    if(auto sp2 = wp.lock()){
    /* if(wp2.lock()){ */
        cout << "转换成功"<< endl;
        sp2->print();
    }else{
        cout << "转换失败" << endl;
    }
    cout << "----" << endl;
    sp.reset(new Point{3,4}); // 资源替换了 原来的就要被删除
    cout << wp.expired() << endl;
}

int main(int argc, char * argv[])
{
    test1();
    return 0;
}

