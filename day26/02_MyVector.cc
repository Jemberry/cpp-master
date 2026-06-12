#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

template <class T>
class MyVector
{
public:
    MyVector();
    ~MyVector();

    void push_back(const T &);
    void pop_back();
    int size() const;
    int capacity() const;

private:
    // 重新分配内存，动态扩容要用的
    void reallocate();

    // 空间的申请与对象的构建分开
    static std::allocator<T> m_alloc;

    T *m_start;
    T *m_finish;
    T *m_end_of_storage;
};

// 静态成员类外初始化
template <class T>
std::allocator<T> MyVector<T>::m_alloc; // 调用的是allocator的默认构造函数

// 构造函数
template <typename T>
MyVector<T>::MyVector()
    : m_start(nullptr), m_finish(nullptr), m_end_of_storage(nullptr)
{
}

// 元素个数
template <class T>
int MyVector<T>::size() const
{
    return m_finish - m_start;
}

// 容量
template <class T>
int MyVector<T>::capacity() const
{
    return m_end_of_storage - m_start;
}
// 析构函数
template <typename T>
MyVector<T>::~MyVector()
{
    if (m_start)
    {
        // 销毁所有元素
        while (m_start != m_finish)
        {
            m_alloc.destroy(--m_finish);
        }
        // 释放所有空间
        m_alloc.deallocate(m_start, capacity());
    }
}

// 尾部添加元素
template <typename T>
void MyVector<T>::push_back(const T &value)
{
    // 判断是否需要扩容
    if(size() == capacity()){
        // 如果需要扩容
        reallocate();
    }
    // 扩容
    // 如果不需要, 直接在尾部插入 在m_finish位置构建元素
    m_alloc.construct(m_finish, value);
    // m_finish逻辑后移
    ++m_finish;
}

// 扩容空间
template <typename T>
void MyVector<T>::reallocate()
{
    // 获取老容量
    int oldCapacity = capacity();
    // 计算一下新容量
    int newCapacity = oldCapacity > 0 ? oldCapacity * 2 : 1;
    // 根据新容量申请空间
    T *temp = m_alloc.allocate(newCapacity);
    // 数据迁移 老空间的元素迁移到新空间中
    // 使用算法库中的uninitialized_copy()函数
    std::uninitialized_copy(m_start, m_finish, temp);
    // 判断指针是否为空
    if (m_start)
    {
        // 老空间的元素销毁掉
        while (m_start != m_finish)
        {
            // 从后往前销毁
            m_alloc.destroy(--m_finish);
        }
        // 释放老空间的元素
        m_alloc.deallocate(m_start, oldCapacity);
    }
    // 更新底层3个指针
    m_start = temp;
    m_finish = temp + oldCapacity;
    m_end_of_storage = temp + newCapacity;
}

// 删除末尾元素
template <typename T>
void MyVector<T>::pop_back()
{
    // 销毁最后一个元素
    // 注意!!m_finish 要往左移动一个位置
    m_alloc.destroy(--m_finish);
}


void test1()
{
    MyVector<int> box;
    box.push_back(1);
    cout << "box.size():" << box.size() << endl;
    cout << "box.capacity():" << box.capacity() << endl;
    cout << "-------" << endl;
    box.push_back(2);
    cout << "box.size():" << box.size() << endl;
    cout << "box.capacity():" << box.capacity() << endl;
    cout << "-------" << endl;
    box.push_back(3);
    cout << "box.size():" << box.size() << endl;
    cout << "box.capacity():" << box.capacity() << endl;
    cout << "-------" << endl;
    box.push_back(4);
    cout << "box.size():" << box.size() << endl;
    cout << "box.capacity():" << box.capacity() << endl;
    cout << "-------" << endl;
    box.push_back(5);
    cout << "box.size():" << box.size() << endl;
    cout << "box.capacity():" << box.capacity() << endl;
    cout << "-------" << endl;
    box.pop_back();
    cout << "box.size():" << box.size() << endl;
    cout << "box.capacity():" << box.capacity() << endl;

    // 增强for循环底层使用的是iterator
    // for(auto & e : box)
    // {
    //     cout << e << " ";
    
    // }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
