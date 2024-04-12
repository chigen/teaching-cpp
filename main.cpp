#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>

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



int main()
{
    // 4.6 4.9 4.19
    int val1 = 12, val2 = 5;
    // cout << val1 % val2 << " " << val1 / val2 <<endl;
    // cout << 16.0 / 10 << endl;

    // // false = 0, true = 1
    // bool flag = -1;
    // cout << flag << endl;
    
    // val1 = 0;
    // if (val1){
    //     cout << "val1" << endl;
    // }

    // cout << !(val1 == val2) << endl;

    // bool flag = true;
    // if (!flag){

    // }



    // int val1 = 12;
    // int val2 = 5;
    // cout << "val1/val2 = " << val1/val2 << endl;

    // vector<string> text {"qwer", "wasd", "not empty", "", "after an empty"};
    // // vector<string> text {};
    // if (!text.empty() && text[1] == "wasd"){
    //     cout << "the second string in this text is wasd" << endl;
    // }

    // 4.9

    // char str[10] = "hello1234";

    // bool flag = true;
    // int val = 0;
    // if (val){

    // }

    // int val2 = 1==2;

    // // 数组 vs 单变量
    // // 数组 str [item1, it2, it3, ...]
    // // 指针 *p = str+1
    // // [item1, it2, it3, ...]
    // //         ^
    // //         |
    // //         p


    // const char *cp = str;
    // if (cp != 0 && *cp != 0){
    //     cout << *cp << endl;
    // }

    // int val3 = 3;
    // // if val3 是否为偶数
    // int val4 = val3 % 2;
    // if (val3 % 2 == 0){
    //     cout << "is even" << endl;
    // }

    // int a = 2, b = 3, c = 4;
    // if ((a <= b) && (b <= c)){

    // }
    // a /= 2; // a = a + 2

    // int i = 0;
    // int j = i++;
    // cout << "i: " << i << "j: " << j << endl;


    // vector<int> vec {1,2,3,4,6,7,8};
    // auto iter = vec.begin();
    // cout << *(iter++) << endl;
    // cout << *iter << endl;

    // vector<string> text {"qwer", "wasd", "not empty", "", "after an empty"};
    // text[0].empty();
    // auto iter2 = text.begin();
    // (*iter2).empty();
    // // 给指针指向的内容去成员函数、变量
    // iter2->empty();
    // int a = 2, b = 4;
    // int val5 = (a > b) ? a : b;
    // if (a > 0){


    //     if (a > b) {

    //     }
    // }
    // int grade = 59;
    // string finalgrade = (grade > 90) ? "high pass": (grade < 60) ? "fail" : "pass";
    // int a = 2; // 00000 10
    // int b = 3; // 00000 11
    // a = a << 3;
    // cout << (a & b) << endl;
    // // string s1 = "a string", *p = &s1;
    // // int n = s1.size();
    // // n = (*p).size(); // * has a priority greater than .
    // // n = p->size();

    // unsigned long quiz1 = 0;    // 每一位代表一个学生是否通过考试
    // // 00000000100..00010
    // // 1UL << 12;  // 代表第12个学生通过
    // quiz1 |= (1 << 12);   // 将第12个学生置为已通过
    // quiz1 &= ~(1 << 9);  // 将第9个学生修改为未通过
    // bool stu12 = quiz1 & (1 << 12);   // 判断第12个学生是否通过

    // cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;

	// cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
	// cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
	// cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl;
	// cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl << endl;

	// cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
	// cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
	// cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
	// cout << "long long:\t" << sizeof(long long) << " bytes" << endl << endl;

	// cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
	// cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
	// cout << "long double:\t" << sizeof(long double) << " bytes" << endl << endl;

    // int ii = 3;
    // cout << "ii:" << sizeof(ii) << " bytes" << endl;


    // int ia[10];
    // size_t sz = sizeof(ia)/sizeof(*ia);
    // cout << sz << endl;

    // int i3 = 4, i4 = i3;

    // if (a < b){
    //     if (a < 0){
    //         a = b;
    //     }
    // }
    // else {

    // }

    char a = '4';
    switch (a)
    {
        case '5':
            cout << "a = 5" << endl;
            break;
            
        case '4':
            cout << "a = 4" << endl;
            break;

        default:
            cout << "a = other" << endl;
            break;
    }

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

    // for (int i, j; cout << "Input two integers:\n", cin >> i >> j; )
    // {
    //     try {
    //         if (j == 0) 
    //             throw runtime_error("divisor is 0");
    //         cout << i / j << endl;

    //         cout << "\nTry again? Enter y or n" << endl;
    //         char c;
    //         cin >> c;
    //         if (!cin || c == 'n')
    //             break;
    //     }
    //     catch (std::exception& err) {
    //         cout << err.what() << "\nTry again? Enter y or n" << endl;
    //         char c;
    //         cin >> c;
    //         if (!cin || c == 'n')
    //             break;
    //     }
    // }
}
