#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

struct Book{
    string name = {};
    int price = 0;
    string category = {};

    Book (string name, int price, string cate)
        : name(name), price(price), category(cate){}
};

int main()
{
    int val1 = 12;
    int val2 = 5;
    cout << "val1/val2 = " << val1/val2 << endl;

    vector<string> text {"qwer", "wasd", "not empty", "", "after an empty"};
    // vector<string> text {};
    if (!text.empty() && text[1] == "wasd"){
        cout << "the second string in this text is wasd" << endl;
    }

    const char *cp = "hello";
    if (cp && *cp){
        cout << *cp << endl;
    }

    string s1 = "a string", *p = &s1;
    int n = s1.size();
    n = (*p).size(); // * has a priority greater than .
    n = p->size();

    unsigned long quiz1 = 0;    // 每一位代表一个学生是否通过考试
    // 1UL << 12;  // 代表第12个学生通过
    quiz1 |= (1UL << 12);   // 将第12个学生置为已通过
    quiz1 &= ~(1UL << 12);  // 将第12个学生修改为未通过
    bool stu12 = quiz1 & (1UL << 12);   // 判断第12个学生是否通过
}
