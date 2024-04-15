#include "first.hpp"

int fact(int val)
{
    // recursion
    // if (val == 0 || val == 1) 
    //     return 1;
    // else 
    //     return val * fact(val-1);

    // use loop
    int res = 1;
    while (val>1){
        res *= val;
        --val;
    }
    return res;
}