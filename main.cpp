#include <iostream>
#include <vector>
#include <string>

#include "first.hpp"

using namespace std;

struct ListNode {
    // 链表
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}

    ~ListNode() {
        delete next;
    }
};

int main()
{
    // int i = 1;
    // // python 
    // i += 1; //2
    // int j = ++i; // j = 3
    // int k = i++; // k = 3 , i = 4

    // int i = 42;
    // int &r = i; // &紧随类型名出现，因此是声明的一部分，上是一个引用
    // int *p; // *紧随类型名出现，因此是声明的一部分，P 是 一个指针
    // p = &i; // &出现在表达式中，是一个取地址符
    // *p = 1; // *出现在表达式中，是一个解引用符
    // int &r2 = *p; // &是声明的一部分，*是一个解引用符

    // void* vp;
    // vp = &i;

    // // pointer
    // double val = 2.22;
    // double *pVal = &val;
    // // auto aVal = pVal;
    // double *pVal2 = pVal;
    // cout << "val's address: " << pVal << endl;
    // cout << "val: " << *pVal << endl;
    // cout << val << " " << *pVal << " " << *pVal2 << endl;
    // *pVal2 = 3.333;
    // cout << val << " " << *pVal << " " << *pVal2 << endl;

    // vp = &val;

    // int* iPtr1, i1 = 1, i2 = 2, i3 = 3, *iPtr2;

    // // void type pointer 
    // double obj = 6.8;
    // int obj2 = 3, *pObj = &obj2;
    // void *pv = &obj;
    
    // pv = pObj;

    // int ival = 1024;
    // int *pi = &ival;
    // int **ppi = &pi;
    // cout << **ppi << endl;
    // cout << *ppi << endl;   
    // cout << pi << endl; 

    // const int costI = 2;
    // const int &refVal = ival;
    int i = 0; 
    const int i2 = i; // 顶层const

    int *const ptr = &i; // 顶层const
    // ptr is const
    // // *ptr = 3;
    // // ptr = &ival; // error
    const int *ptr2 = &i; //底层const
    // *ptr2 is const
    i++;
    // // ptr2 = &ival; // correct
    // // *ptr2 = 3; // error
    // cout << *ptr << endl;
    // *ptr = 2;
    // cout << *ptr << endl;

    // double ival = 10.1, *pVal = &ival;
    // auto pVal2 = pVal;
    // auto ival2 = 1 + 1.23;
    // int ii = 0, &r = ii; 
    // auto a = r;
    // cout << ii << " " << a << endl;
    // a = 2;
    // cout << ii << " " << a << endl;

    // int *ptr = &ii;
    // auto ptr2 = ptr;

    const auto i3 = i2;
    // 变量类型   变量    值
    const double ival = 1.111;
    decltype(ival) ival2 = 22.1;

    vector<int> vec{1,2,3,4,5};
    for(int i=0;i<vec.size(); ++i){
        auto val = vec[i];
        cout << val;
    }

    // auto variable_name = value;
    // another_variable is defined before
    // decltype(another_variable) variable_name = value;

    // i = 4;
    // auto const& cstRefI = i;
    
    // shared_ptr<int> sp1 = make_shared<int> (42);
    // shared_ptr<int> sp2 = sp1;
    // *sp2 = 43;
    
    // unique_ptr<int> up1 = make_unique<int> (10);
    // auto curr = up1.get();

    // int *p6 = &i;
    // {
    //     int iTemp = 4;
    //     p6 = &iTemp;
    // }
    // cout << *p6 << endl;

    // constexpr int mf = 20;

    // ListNode* firstNode = new ListNode(1);
    // ListNode* secondNode = new ListNode(2);
    // firstNode->next = secondNode;

    
    // string s1{"first"}, s2{"second"};
    // auto c = s1[2];


    // int double char ...
    // struct // 结构体 = 类
    // class // 类
    // 变量类型   变量    值
    // Model model1 = xxx;
    struct Sales_data 
    {
    int price = 0;
    string name = "";
    } book2, book3;


    Sales_data book1;
    book1.name = "3 bodies";
    book1.price = 99;
    return 0;
}
