#include <iostream>
#include <vector>
#include <string>

#include "first.hpp"

using namespace std;

int main()
{
    // pointer
    double val = 2.22;
    double *pVal = &val;
    // auto aVal = pVal;
    double *pVal2 = pVal;
    cout << "val's address: " << pVal << endl;
    cout << "val: " << *pVal << endl;
    cout << val << " " << *pVal << " " << *pVal2 << endl;
    *pVal2 = 3.333;
    cout << val << " " << *pVal << " " << *pVal2 << endl;

    // void type pointer
    double obj = 6.8;
    int obj2 = 3, *pObj = &obj2;
    void *pv = &obj;
    
    pv = pObj;

    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;
    cout << **ppi << endl;
    cout << *ppi << endl;   
    cout << pi << endl; 

    int i = 0; 
    int *const ptr = &i;
    // ptr = &ival; // error
    const int *ptr2 = &i;
    // ptr2 = &ival; // correct
    cout << *ptr << endl;
    *ptr = 2;
    cout << *ptr << endl;

    int ii = 0, &r = ii; 
    auto a = r;
    cout << ii << " " << a << endl;
    a = 2;
    cout << ii << " " << a << endl;

    i = 4;
    auto const& cstRefI = i;
    
    shared_ptr<int> sp1 = make_shared<int> (42);
    shared_ptr<int> sp2 = sp1;
    *sp2 = 43;
    
    unique_ptr<int> up1 = make_unique<int> (10);
    auto curr = up1.get();

    int *p6 = &i;
    {
        int iTemp = 4;
        p6 = &iTemp;
    }
    cout << *p6 << endl;

    constexpr int mf = 20;

    string s1{"first"}, s2{"second"};
    auto c = s1[2];
    return 0;
}
