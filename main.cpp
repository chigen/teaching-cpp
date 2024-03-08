#include <iostream>
#include <vector>
#include <string>

#include "first.hpp"

using namespace std;

// 不推荐使用同名的全局变量
int reused = 42; // reused有全局作用域

const double pi = 3.1415926;

void printVec(vector<int>& vec){
    int len = vec.size();

    for(int i=0;i<len; ++i){
        vec[i] += 1;
        cout << vec[i] << " ";
    }
}

int main()
{
    // 声明 定义 使用（赋值...)
    bool b = 42; // b为true 初始化 = （声明+定义+赋值）
    int i = b; // i的值为1 初始化
    i = 3.14; // i的值为3 赋值
    char c = 'b'; 
    char cc = c;
    string str = "he\nllo";
    string str2 = "world";
    cout << str << str2 << endl;

    // 右值
    vector<int> vecA(100,0);
    vector<int> vecB;
    vecB = std::move(vecA);

    // 列表初始化
    int units_sold = 0; 
    int units_sold2 = {0};
    int units_sold3{0};
    int units_sold4(0); // 传统的构造函数初始化

    // 输出全局变量unused
    cout << "Value of reused: " << reused << endl;  //42
    // 输出局部变量unused
    int reused = 0;
    cout << "Value of reused: " << reused << endl;
    // 显式访问全局变量unused (optional)
    cout << "Value of reused: " << ::reused << endl;

    // reference
    int val = 1024;
    cout << "ori of val: " <<val << endl;
    int &refVal = val; // refVal指向val
    // int &refVal2; // 错误，引用必须初始化
    refVal = 2; // val的值变为2
    cout << "Value of val: " << val << endl;

    // pointer
    // double val = 2.22;
    // double *pVal = &val;
    // double *pVal2 = pVal;
    // cout << val << " " << *pVal << " " << *pVal2 << endl;
    // *pVal2 = 3.333;
    // cout << val << " " << *pVal << " " << *pVal2 << endl;

    // const
    int newI = 2; //初始化
    const int constI = 9;
    newI = 3;

    const int &refConst = constI;
    const int &refConst2 = constI;
    
    float fa = 1.111;
    float &refA = fa;


    // 类型别名
    typedef int id;
    id firstObj = 0;
    using ID = int;
    ID secondObj = 1;

    return 0;
}
