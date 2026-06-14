#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    // int* p = &a;
    // p = &b;
    // *p = 100;

    // const int* p = &a;
    // p = &b;
    // *p = 100;  //ERROR!

    // int* const p = &a;
    // p = &b; // ERROR!
    // *p = 100;

    const int* const p = &a;
    // p = &b; // ERROR!
    // *p = 100; // ERROR!
}
