#include "first.hpp"

// int fact(int val)
// {
//     // recursion
//     if (val == 0 || val == 1) 
//         return 1;
//     else 
//         return val * fact(val-1);

//     // use loop
//     // int res = 1;
//     // while (val>1){
//     //     res *= val;
//     //     --val;
//     // }
//     // return res;
// }

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

// bool isShorter (string &s1, string &s2){
//     return s1.size() < s2.size();
// }

// 交换两个int类型的变量的值
void swap(int &a, int &b){
    int swap1 = a;
    a = b;
    b = swap1;
}

void bubbleSort(vector<int> &vec){
    int n = vec.size();
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<n-1-i; ++j){
            // 如果当前位的值大于下一位的值的话，互换
            if(vec[j] > vec[j+1]){
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}