#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

/*
 * 左值: 能取地址的值 
 *   有名字的变量,对象,字符串常量
 * 右值: 不能取地址的值
 *   没有名字的对象,临时,匿名对象,或者临时变量, 字面值常量
 *
 * 引用分类:
 * 1.左值引用
 *    非const引用
 *    const引用
 * 2.右值引用
 *    数据类型 && 引用名 = 右值
 *  
 */
class String
{
public:
    // default no arg constructor
    String()
    /* : _pstr(nullptr) */
    : m_pstr(new char[1]())
    {
        cout << "String()" << endl;
    }
	// args constructor
    String(const char *pstr)
    : m_pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(m_pstr, pstr);
    }
	// copy constructor
    String(const String & rhs)
    : m_pstr(new char[strlen(rhs.m_pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(m_pstr, rhs.m_pstr);
    }
	// operator =
    String & operator=(const String & rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs)
        {
            if(m_pstr)
            {
                delete [] m_pstr;
            }
            m_pstr = new char[strlen(rhs.m_pstr) + 1]();
            strcpy(m_pstr, rhs.m_pstr);
        }
        return *this;
    }
	// length
    size_t length() const
    {
        size_t len = 0;
        if(m_pstr)
        {
            len = strlen(m_pstr);
        }

        return len;

    }
	// c style string
    const char * c_str() const
    {
        if(m_pstr)
        {
            return m_pstr;
        }
        else
        {
            return nullptr;
        }
    }

	// destructor
    ~String()
    {
        cout << "~String()" << endl;
        if(m_pstr)
        {
            delete [] m_pstr;
            m_pstr = nullptr;
        }
    }

    void print() const
    {
        if(m_pstr)
        {
            cout << "m_pstr = " << m_pstr << endl;
        }else{
            cout << endl;
        }
    }

private:
    char * m_pstr;
};


class Point{};

void test1()
{
    // 常见的的左值
    int a = 1;
    int b = 2;
    &a;
    &b;
    Point pt;
    &pt;
    &"hello";
    // 常见的右值
    /* &(a + b); */
    /* &a++; */
    /* &Point{}; */
    /* &100; */
}

void test2()
{
    int a = 1;
    // 非const引用 : 只能绑定左值 不能绑定右值
    int & ref = a;
    ref = 2;
    /* int & ref2 = 1; */

    // const引用: 既能绑定左值 又能绑定右值
    const int & ref3 = a;
    /* ref3 = 2; */
    const int & ref4 = 1;

    // const引用不能区分左值还是右值--->使用右值引用区分
    
    // 右值引用: 数据类型 && 右值引用名 = 所绑定的目标(右值)
    /* int && ref5 = a; */
    int && ref6 = 1;
}

int main(int argc, char * argv[])
{
    test1();
    return 0;
}

