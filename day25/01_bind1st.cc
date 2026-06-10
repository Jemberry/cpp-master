#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;


/*
std::bind1st / std::bind2nd 
绑定函数参数, 绑定二元函数的参数为某个固定值
*/

/*
struct less
{
    bool operator()(int lhs , int rhs = 3) const
    {
        return lhs < rhs;
        return 3 < rhs
        return lhs < 3; 
    }
}

void func(int a=1 , int b = 2 ){}

// void (int,int) 函数类型
func(1,2);

// void (int) 函数类型
func(1);

// void() 函数类型
func();


}


*/

void test1()
{
    vector<int> box {1,2,3,4,5};
    // 使用remove_if删除大于3的元素
    // auto it = std::remove_if(box.begin(),box.end(), std::less<int>());
    // 上述代码报错 原因是std::less<int>()是一个二元函数, 
    // 而remove_if需要一个一元函数  参数不匹配 如何解决?
    // 如果可以把一个二元函数----->一元函数 可以适配
    // 使用bind1st绑定lhs为3
    // auto it = std::remove_if(box.begin(),box.end(), 
    //      bind1st(std::less<int>(),3));

    // 使用bind2nd绑定rhs为3
    auto it = std::remove_if(box.begin(),box.end(), 
         bind2nd(std::less<int>(),3));

    box.erase(it, box.end());
    std::for_each(box.begin(), box.end(),
        [](int num){
            cout << num << " ";
        }
    );
    cout << endl;
}


int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
