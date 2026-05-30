#include <iostream>

using std::cout;
using std::endl;

/*
 * 模拟实现RAII, 管理任意类型的资源
 *
 */

template <typename T>
class RAII
{
public:
    // constructor 初始化 
    RAII(T * p)
    : m_p(p)
    {
        cout << "init resource..." << endl;
    }
    // destructor  释放资源
    ~RAII()
    {
        cout << "release resource..." << endl;
        if(m_p){
            delete m_p;
            m_p = nullptr;
        }
    }
    // delete copy function
    RAII(const RAII &) = delete;
    RAII& operator=(const RAII &) = delete;

    // 提供访问资源的操作
    // operator->
    T * operator->()
    {
        return m_p;
    }
    // operator*
    T & operator*()
    {
        return *m_p;
    }
    // get() : 获取原始指针
    T * get()
    {
        return m_p;
    }
private:
    // 资源类型的指针 底层指针 裸指针 原始指针
    T * m_p;
};

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

void test1()
{
    // 栈对象
    RAII<int> raii{ new int{100} };
    cout << *raii << endl;
    cout << "------" << endl;
    RAII<Point> raii2 { new Point{1,2} };
    raii2->print();
    (*raii2).print();
    raii2.get()->print();
}

int main(int argc, char * argv[])
{
    test1();
    return 0;
}

