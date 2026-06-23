#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main()
{
    // 1. 基本数据结构：null, 布尔, 数字, 字符串
    json j1;
    cout << j1.dump() << endl; // null
    json j2 = false;
    cout << j2.dump() << endl; // false
    json j3 = 2.67;
    cout << j3.dump() << endl; // 2.67
    json j4 = "花生";
    cout << j4.dump() << endl; // "花生"

    // 2. 初始化列表
    json j5 = { "peanut", "loves", "xixi", 520 };
    cout << j5.dump(2) << endl;

    json j6 = {
        { "name", "花生" },
        { "age", 18 }
    };
    cout << j6.dump(2) << endl;

    // 3. 解决歧义
    json j7; // null
    json j8 = ""; // ""
    json j9 = json::array();
    cout << j9.dump(2) << endl; //[]
    json j10 = json::object();
    cout << j10.dump(2) << endl; //{}

    //  如何表示: [["currency", "USD"], ["value", 42.99]]
    json d1 = { { "currency", "USD" }, { "value", 42.99 } };
    cout << d1.dump(2) << endl;

    json d2 = json::array({ { "currency", "USD" }, { "value", 42.99 } });
    cout << d2.dump(2) << endl;

    // 4. 动态构建json
    json d4; // null
    d4["pi"] = 3.141; // null -> object
    d4["happy"] = true;
    d4["name"] = "Niels";
    d4["nothing"] = nullptr;
    d4["answer"]["everything"] = 42;
    d4["list"] = { 1, 0, 2 };
    d4["object"] = { { "currency", "USD" }, { "value", 42.99 } };
    // cout << d4.dump(2) << endl;

    json d5; // null
    d5["pi"] = 3.141; // null -> object
    d5["happy"] = true;
    d5["name"] = "Niels";
    d5["nothing"] = nullptr;
    d5["answer"]["everything"] = 42;
    // 数组
    d5["list"].push_back(1);
    d5["list"].push_back(0);
    d5["list"].push_back(2);
    // 对象
    d5["object"].emplace("currency", "USD");
    d5["object"].emplace("value", 42.99);
    cout << d5.dump(2) << endl;
}
