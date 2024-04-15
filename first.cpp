#include "first.hpp"

int fact(int val)
{
    // recursion
    if (val == 0 || val == 1) 
        return 1;
    else 
        return val * fact(val-1);

    // use loop
    // int res = 1;
    // while (val>1){
    //     res *= val;
    //     --val;
    // }
    // return res;
}
// param 形参
// vector<int> ivec = vec;
int sum(int n, vector<int> ivec){
    int result = 0;
    static int count = 0;

    for (auto& num : ivec){
        result += num;
    }


    count++;
    cout << "count: "<< count << endl;

    return result;
}

bool isShorter (string &s1, string &s2){
    return s1.size() < s2.size();
}

void foo(vector<int> &v1, vector<int> &v2, vector<int> &v3){
    v1.push_back(-1);
    v2.push_back(-2);
    v3.push_back(-3);
    return;
}

void bar(int *a){
    *a *= 2;
}

// 交换两个int类型的变量的值
void swap(int &a, int &b){
    int swap1 = a;
    a = b;
    b = swap1;
}

// 阶乘 n*n-1 ... * 1
int factori(int n){
    int result = 1;

    for(int i=1; i<=n; ++i){
        result = result * i; 
    }

    return result;
}