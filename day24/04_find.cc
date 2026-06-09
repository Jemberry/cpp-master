#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

/*
find: 找到了返回对应位置的迭代器 没找到返回end()
find_if: 带条件的查找
*/

// find
void test1()
{
    vector<int > box { 1, 2, 3, 3, 4, 5};
    auto it = find(box.begin(), box.end(), 3);
    if(it != box.end()){
        cout << "find it" << endl;
        cout << *it << endl;
    }
    ++it;
    cout << *it << endl;
    ++it;
    cout << *it << endl;
}

bool func(int num)
{
    return num > 3;
}

// 函数对象
struct OverThree
{
    bool operator()(int num)
    {
        return num > 3;
    }
};


// find_if: 第3个参数是个一元谓词: 返回值为bool类型的一个参数的函数
void test2()
{
    vector<int > box { 1, 2, 3, 3, 4, 5};
    // auto it = find_if(box.begin(), box.end(), func);
    // auto it = find_if(box.begin(), box.end(), &func);
    // auto it = find_if(box.begin(), box.end(), OverThree());
    auto it = find_if(box.begin(), box.end(), 
        [](int num)->bool{
            return num > 3;
        }
    );
    // 修改成lambda
    cout << *it << endl;
    ++it;
    cout << *it << endl;

}

// replcae
void test3()
{
    vector<int > box { 1, 2, 3, 3, 4, 5};
    replace(box.begin(), box.end(), 3, 100);
    std::copy(box.begin(), box.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

// replcae_if: 带条件的替换
void test4()
{
    vector<int > box { 1, 2, 3, 4, 5};
    replace_if(box.begin(), box.end(), 
        [](int num)->bool{
            return num > 3;
        },
        100
     );
    std::copy(box.begin(), box.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
// remove: 删除元素
// 1.移动元素
// 2.删除元素
void test5()
{
    vector<int > box { 1, 2, 3, 4, 5};
    auto it = remove(box.begin(), box.end(), 3);
    cout << *it << endl;
    // 结合erase删除元素
    box.erase(it, box.end());
    std::copy(box.begin(), box.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}



// remove_if: 带条件的删除
void test6()
{
    vector<int > box { 1, 2, 3, 4, 5};
    auto it = remove_if(box.begin(), box.end(), 
        [](int num)->bool{
            return num > 3;
        }
    );
    // 结合erase删除元素
    // box.erase(it, box.end());
    std::copy(box.begin(), box.end(), ostream_iterator<int>(cout, " "));
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
