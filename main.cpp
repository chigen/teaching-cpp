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

    // if (num >= 0) {
    //     cout << num;
    //     num ++;
    // }

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
    // else {
    //     if(num < 0){
    //         cout << "num is less than 0" << endl;
    //     }
    //     else {
    //         cout << "num is equal to 0" << endl;
    //     }
    // }

    // Book threeBody("three body", 98, "sci-fi");

    // if(threeBody.price < 100){
    //     cout << "not expensive" << endl;
    // }
    // if (threeBody.category == "sci-fi"){
    //     cout << "is sci-fi book" << endl;
    // }

    // while
    // vector<int> vec{1,2,3,4,6,7,8};

    // int vecLen = vec.size();
    // int index = 0;
    // while(index<vecLen)
    // {
    //     if(index%2==1){
    //         break;
    //     }
    //     cout << "current index: " << index << endl;
    //     cout << "value: " << vec[index] << endl;
        
        
    //     index++;
    //     // break;
    // }

    // // for
    // for(int i=0; i<vecLen;){
    //     cout << "current index: " << i << endl;
    //     cout << "value: " << vec[i] << endl;
        
    //     ++i;
    // }

    // int i=0;
    // for (;;){
    //     if(i<vecLen)
    //         break;
        
    //     cout << "current index: " << i << endl;
    //     cout << "value: " << vec[i] << endl;
    //     ++i;
    // }

    // {
    //     int i=0,j=1;
    //     while(i<vecLen){
    //         cout << "current index: " << i << endl;
    //         cout << "value: " << vec[i] << endl;

    //         ++i;
    //     }
    // }

    // string str = "forloop";
    // for(decltype(str.size()) index=0; index<str.size(); index++){
    //     str[index] = toupper(str[index]);
    // }
    // cout<<str<<endl;

    // range for
    // vector<int> vec{1,2,3,4,6,7,8};

    // for (int i=0;i<vec.size(); ++i){
    //     int num = vec[i];
    //     num *= 2;
    // }

    // for(int num : vec){
    //     num *= 2;
    // }

    // for (int i=0;i<vec.size(); ++i){
    //     vec[i] *= 2;
    // }
        // declaration: expression
    // for(int &num : vec){
    //     num *= 2;
    // }
    // for(auto &num : vec){
    //     cout << num << " ";
    // }

    // string
    // 定义和初始化
    // string s1;
    // string s2(s1); // or string s2 = s1;
    // string s3 = "value"; // string s3("value")
    // string s4 = {"list initialize"};
    // string s5(5, 'a'); //初始化为由连续5个字符c组成的串

    // auto len = s5.size();
    // bool empty = s1.empty();

    // cout << s4[2];

    // string s6 = s3 + ' ' + s4 + " byebye";

    // string temp = s4.substr(5,4);
    // cout << "sub string: " << temp << endl;

    // int i[3];
    // int j[3] = i[3]; //error

    // string str1, str2;
    // cin >> str1;
    // cout << "str1: " << str1 << endl;
    // cin >> str1 >> str2;
    // cout << "str1: " << str1 << " str2: "<< str2 << endl;

    

    // 容器
    // 类模版 
    // vector<double> vec2;
    // vector<double> vec3 = vec2; // vec3(vec2);
    // vector<double> vec4{4,3,3,6,6,7};
    // vector<double> vec5(5);
    // vector<string> vecStr(4, "abc");

    // vec4.push_back(3.2);
    // vec4.push_back(4.5);
    // vec4.push_back(5.5);

    //初始化

    // list init
    // value init

    // traditional list
    // 变量类型 变量名[n] = {}
    // int i[3];
    // int i2[3] = {2, 4, 6};
    // int i3[3] = {2, 4};
    // int i4[] = {2, 3, 4, 5, 1010};
    // char str[3] = {'c' , 'b', 'd'};

    // cout << i << endl;
    // for(int index=0;index<5;++index){
    //     cout << i4[index] << " ";
    // }
    // for(int* ip=i4, count=0;count<=5;count++, ip++){
    //     cout << *ip << " ";
    // }

    // // for (int j=0; j<3; j++){
    // //     cout << i[j];
    // // }
    // cout << i << endl;
    // int *ip = i;
    // int *ip2 = &i2[1];


    // string list[3] = {"hello", "hey", "hi"};

    // constexpr int len = 4;
    // int numList[len];
    // // vector<int> vecList(10, 1);
    // // cout << "list: " << list << endl;
    // cout << "numList: " << numList << endl;

    // // 迭代器 
    // int *pList = numList;
    // // pList = &numList[2];
    // for(int i=0;i<len;++i){
    //     *pList = i+3;
    //     cout << *pList << endl;
    //     pList++;
    // }
    
    // cout << "vector" << vecList << endl; // error

    // // 多维数组
    // vector<vector<int>> matrix(3, vector<int>(3, 0));
    // matrix[0].push_back(1);
    // matrix.push_back(vector<int>{2,3,5});

    // int mat2[3][4];
    // for(auto p=mat2; p!=mat2+3; ++p){
    //     for(auto q = *p; q!=*p+4; ++q){
    //         cout<< *q << endl;
    //     }
    // }

    vector<int> vec{1,3,4,5,6};
    // auto it = vec.begin();
    // vector<int>::iterator it2 = vec.begin();

    // for(auto it=vec.begin(); it!=vec.end(); ++it){
    //     cout << *it << endl;
    // }


    int i1 = 1, i2 = 3;
    if(i1 == 1){
        cout << "i1 is 1" << endl;;
    }
    // if(i1 = 2){
    //     cout << "give i1 a new value, 2" << endl;
    // }
    if(i1 != 2){
        cout << "i1 is not 2" << endl;
    }
    if(i1 < 5){
        cout << "i1 is less than 5" << endl;
    }
    if (i1>=1){
        cout << "i1 is greater or equal to 1"<< endl;
    }

    if (i1 == 1 && i2 == 2){
        cout << "and" << endl;
    }
    if (i1 == 1 || i2 == 2){
        cout << "or" << endl;
    }


    vector<string> text{"hello", "world", "end", "", "hi", " again"};
    for(auto it=text.begin(); it!=text.end() && !(*it).empty(); ++it){
        cout << *it << " ";
    }
    cout << "haha";

    return 0;
}
