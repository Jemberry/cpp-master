#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

class Point
{
public:
    Point(int x, int y)
        : m_x(x), m_y(y)
    {
        cout << "Point(int x, int y)" << endl;
    }
    // copy constructor
    Point(const Point & p)
        : m_x(p.m_x), m_y(p.m_y)
    {
        cout << "Point(const Point & p)" << endl;
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

// emplace_back vs push_back
// emplace VS insert
void test1()
{
    list<Point> box;
    Point pt{ 1, 2};
    cout << "-------" << endl;
    // push_back 会调用拷贝构造
    box.push_back(pt);
    cout << "----" << endl;
    // emplace_back , 参数是构造函数的参数 会调用构造函数
    box.emplace_back(3,4);
    cout << "------" << endl;
    Point pt2{ 5, 6};
    auto it = box.begin();
    it = box.insert(it, pt2); // 调用的是拷贝构造函数
    cout << "------" << endl;
    box.emplace(it, 3,4); // 调用的是构造函数
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
