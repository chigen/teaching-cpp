#include <iostream>
#include <vector>
#include <string>

#include "first.hpp"

using namespace std;
// 不推荐使用同名的全局变量
int reused = 42; // reused有全局作用域

int main()
{
    // 列表初始化
    // int units_sold = 0;
    // int units_sold2 = {0};
    // int units_sold3{0};
    // int units_sold4(0); // 传统的构造函数初始化

    // bool b = 42; // b为true
    // int i = b; // i的值为1
    // i = 3.14; // i的值为3
    // double pi = i; // pi的值为3.0
    // cout << b << " " << i << " " << pi << endl;
    // cout << "Value of pi: " << pi << endl;

    // // 输出全局变量unused
    // cout << "Value of reused: " << reused << endl;
    // // 输出局部变量unused
    // int reused = 0;
    // cout << "Value of reused: " << reused << endl;
    // // 显式访问全局变量unused (optional)
    // cout << "Value of reused: " << ::reused << endl;

    int val = 1024;
    int &refVal = val; // refVal指向val
    // int &refVal2; // 错误，引用必须初始化
    refVal = 2; // val的值变为2
    cout << "Value of val: " << val << endl;

    return 0;
}