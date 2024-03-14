#include <iostream>
#include <vector>
#include <string>

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
    // int num = 0;
    // cin >> num;

    // if(num >= 0){
    //     cout << "num is >= 0" << endl;
    // }
    // else{
    //     cout << "num is < 0" << endl;
    // }

    // // 嵌套if
    // if(num > 0){
    //     cout << "num is greater than 0" << endl;
    // }
    // else if(num < 0){
    //     cout << "num is less than 0" << endl;
    // }
    // else {
    //     cout << "num is equal to 0" << endl;
    // }

    // Book threeBody("three body", 98, "sci-fi");
    // if(threeBody.price < 100){
    //     cout << "not expensive" << endl;
    // }
    // if (threeBody.category == "sci-fi"){
    //     cout << "is sci-fi book" << endl;
    // }

    // // while
    // vector<int> vec{1,2,3,4,6,7,8};
    // int vecLen = vec.size();
    // int index = 0;
    // while(index<vecLen){
    //     cout << "current index: " << index << endl;
    //     cout << "value: " << vec[index] << endl;
    // }

    // // for
    // for(int i=0; i<vecLen; ++i){
    //     cout << "current index: " << i << endl;
    //     cout << "value: " << vec[i] << endl;
    // }

    // string str = "forloop";
    // for(decltype(str.size()) index=0; index<str.size(); index++){
    //     str[index] = toupper(str[index]);
    // }

    // // range for
    // for(auto& num : vec){
    //     num *= 2;
    // }

    // string
    // 定义和初始化
    string s1;
    string s2(s1); // or string s2 = s1;
    string s3 = "value"; // string s3("value")
    string s4{"list initialize"};
    string s5(5, 'c'); //初始化为由连续5个字符c组成的串

    // string str1, str2;
    // cin >> str1;
    // cout << "str1: " << str1 << endl;
    // cin >> str1 >> str2;
    // cout << "str1: " << str1 << " str2: "<< str2 << endl;

    string temp = s4.substr(5,4);
    cout << "sub string: " << temp << endl;

    // 容器
    // 类模版 

    //初始化

    // list init
    // value init

    // traditional list
    string list[3] = {"hello", "hey", "hi"};
    int len = 4;
    int numList[len];
    cout << "list: " << list << endl;
    cout << "numList: " << numList << endl;

    // 多维数组
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    matrix[0].push_back(1);
    matrix.push_back(vector<int>{2,3,5});

    int mat2[3][4];
    for(auto p=mat2; p!=mat2+3; ++p){
        for(auto q = *p; q!=*p+4; ++q){
            cout<< *q << endl;
        }
    }
    

    return 0;
}
