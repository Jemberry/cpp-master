#include "person.pb.h"
#include <iostream>
#include <string>

using namespace std;
using namespace test;

int main()
{
    Person p1;
    p1.set_id(100);
    p1.set_name("test");
    p1.set_email("example@gmail.com");

    // 序列化
    string output;
    p1.SerializeToString(&output);
    cout << "size: " << output.size() << endl;
    cout << "output: " << output << endl;

    // 反序列化
    Person p2;
    cout << "p2.id: " << p2.id()
         << ", p2.name: " << p2.name()
         << ", p2.email: " << p2.email() << endl;
    p2.ParseFromString(output);
    cout << "p2.id: " << p2.id()
         << ", p2.name: " << p2.name()
         << ", p2.email: " << p2.email() << endl;
}
