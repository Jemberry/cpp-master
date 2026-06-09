#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
#include <deque>

using namespace std;

/*

*/


// sort
void test1()
{
    // vector<int > box { 3,1,5,2,4};
    deque<int > box { 3,1,5,2,4};
    sort(box.begin(), box.end());
    copy(box.begin(), box.end(), ostream_iterator<int>{cout , " "});
    cout << endl;
    // vector<Student> box;
}

// max / min 返回最大最小值
void test2()
{
    int a = 1;
    int b = 2;
    int maxValue = max(a, b);
    cout << "maxValue = " << maxValue << endl;
    cout << "----" << endl;
    int minValue = min(a, b);
    cout << "minValue = " << minValue << endl;

    /*
    // 自定义比较器
    struct StudentCompare{
        bool operator()(const Student &s1, const Student &s2)
        {
            return s1.age > s2.age;
        }
    };
    Student s1{1,"zs",20};
    Student s2{2,"ls",21};
    max(s1,s2,StudentCompare());
    
    */

}

// lower_bound 二分查找第一个大于等于目标值的元素
// upper_bound 二分查找第一个大于目标值的元素
// equal_range 二分查找等于目标值的元素范围的迭代器对 pair对象)
void test3()
{
    vector<int> box{ 1,2 ,3, 4, 5};
    auto it = lower_bound(box.begin(), box.end(), 3);
    cout << *it << endl;
    cout << "------ " << endl;
    auto it2 = upper_bound(box.begin(), box.end(), 3);
    cout << *it2 << endl;

}

// equal_range 二分查找等于目标值的元素范围的迭代器对 pair对象)
// 返回值为pair对象,first是指向第一个大于等于目标元素的位置
// second是指向第一个大于目标元素的位置
void test4()
{
    vector<int> box{ 1,2 ,3,3,3, 4, 5};
    auto p = equal_range(box.begin(), box.end(), 3);
    auto itStart = p.first;
    auto itEnd = p.second;
    cout << *itStart << endl;
    cout << *itEnd << endl;
    cout << "-------" << endl;
    copy(itStart,itEnd, ostream_iterator<int>{cout , " "});
    cout << endl;

}

// 集合操作: 并集 交集.....
void test5()
{
    vector<int> box1{1,2,3,4};
    vector<int> box2{4,5,6};
    vector<int> box3;
    // 并集
    set_union(box1.begin(), box1.end(), box2.begin(), box2.end(), back_inserter(box3));
    copy(box3.begin(), box3.end(), ostream_iterator<int>{cout , " "});
    cout << endl;
    
}

void test6()
{
    vector<int> box1{1,2,3,4};
    vector<int> box2{4,5,6};
    vector<int> box3;
    // 交集
    set_intersection(box1.begin(), box1.end(), box2.begin(), box2.end(), back_inserter(box3));
    copy(box3.begin(), box3.end(), ostream_iterator<int>{cout , " "});
    cout << endl;
    
}
int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
    return 0;
}
