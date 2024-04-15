#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>

#include "first.hpp"

using namespace std;

struct Book{
    string name = {};
    int price = 0;
    string category = {};

    Book (string name, int price, string cate)
        : name(name), price(price), category(cate){}
};

/* 
自定义的数据结构
类{
    member funtion
    member variable
}
 */

void testAssert(int value) {
    assert(value > 0); // Assert 用于验证内部状态，只在开发中有效
}

void testThrow(int value) {
    if (value <= 0) {
        throw std::invalid_argument("Value must be positive"); // Throw 用于在运行时处理预见的错误
    }
}


int main()
{
    // try {
    //     testThrow(-1); // 这将抛出异常
    // } catch (const std::exception& e) {
    //     std::cout << "Caught an exception: " << e.what() << std::endl;
    // }

    // testAssert(-1); // 这将在 NDEBUG 未定义的情况下终止程序
    // return 0;

    // string rsp;
    // do {
    //     cout << "Input two strings: ";
    //     string str1, str2;
    //     cin >> str1 >> str2;
    //     cout << (str1 <= str2 ? str1 : str2) 
    //          << " is less than the other. " << "\n\n"
    //          << "More? Enter yes or no: ";
    //     cin >> rsp;
    // } while (!rsp.empty() && tolower(rsp[0]) == 'y');

    // int a = 2, b = 2;
    // assert(a == b && "a == b");

    for (int i, j; cout << "Input two integers:\n", cin >> i >> j; )
    {
        try {
            if (j == 0) 
                throw runtime_error("divisor is 0");
            cout << i / j << endl;

            cout << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
        catch (std::runtime_error& err) {
            cout << err.what() << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }

    cout << fact(5) << endl;
}
