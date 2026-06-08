#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>


using namespace std;

/*
输入流迭代器 istream_iterator
读数据 变量 = *it
*/

void test1()
{
    // 创建istream流迭代器
    istream_iterator<int> it{ cin };
    // 读数据
    int num1;
    int num2;
    num1 = *it;
    ++it;
    num2 = *it;
    cout << num1 << endl;
    cout << num2 << endl;
}
void test2()
{
    // 创建istream流迭代器
    istream_iterator<string> it{ cin };
    // 读数据
    string str1;
    string str2;
    str1 = *it;
    ++it;
    str2 = *it;
    cout << str1 << endl;
    cout << str2 << endl;
}

// 通过键盘输入数据 填充到容器中
void test3()
{
   vector<int> box;
   // 创建输入流迭代器对象作为first
   istream_iterator<int> itFirst{ cin };
   // 创建输入流迭代器对象作为last 
   // 通过istream_iterator的无参构造函数创建的对象作为流的末尾
   istream_iterator<int> itLast{  };

   // 使用std::copy实现
   //  std::copy(itFirst,itLast, box.begin()); // error
   // 需要使用迭代器适配器去实现
   // 创建一个尾部插入的迭代器适配器对象
   back_insert_iterator<vector<int>> it{box};
//    std::copy(itFirst,itLast,it); 
    // 可以利用back_inserter()函数来简化操作
   std::copy(itFirst,itLast, back_inserter(box)); 

    cout << box.size() << endl;
   // 打印数据
   std::copy(box.begin(), box.end(), ostream_iterator<int>{cout," "});

}


int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    test3();
    // test4();
    return 0;
}







