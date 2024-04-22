#include <vector>
#include <iostream>

using namespace std;


// int fact(int val);

int sum(int n, vector<int> ivec);

inline bool isShorter (string &s1, string &s2){
    return s1.size() < s2.size();
}

void swap(int &a, int &b);