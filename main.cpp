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

/* 
自定义的数据结构
类{
    member funtion
    member variable
}
 */



int main()
{

    // vector<int> vec{1,2,3};
    
    // auto iter = vec.begin();
    

    // string s1, s2;
    // cin >> s1 >> s2;
    // // if(s1 == s2){
    // //     cout << "is equal" << endl;
    // // }
    // // else{
    // //     string result = (s1> s2) ? s1 : s2;
    // //     cout << result << endl;
    // // }
    // if (s1.size() == s2.size()){
    //     cout << endl;
    // }
    // else{
    //     auto result = (s1.size() > s2.size()) ? s1.size() : s2.size();
    //     cout << result << endl;
    // }

    // string s = "asdfghhkl";

    // for (int index = 0 ; index<s.size(); ++index){
    //     char &c = s[index];

    // }

    // for (char &c : s){
    //     c = 'X';
    // }
    int i1 = 1;
    int i2 = +i1;
    char c = 'a';
    char c2 = c +1;


    vector<int> vec3;
    if(!vec3.empty() && vec3[0]==2){

    }
    // vector<int> ivec;
    // bool flag = ivec.empty(); 
    // int len = ivec.size();
    // ivec.push_back(42);

    // vector<int> vec2(10,1);
    // for(int index=0;index<=9;index++){
    //     vec2[index] = vec2[index]*2;
    // }

    // for(auto iter=vec2.begin();iter<vec2.end();iter+=1){
    //     *iter *= 2;
    // }
    

   /*读入一组浮点数并把它们存入一个vector 对象，
   将每对相邻整数的和输出出来。
   


   改写你的程序，
   这次要求先输出第1个和最后1个元素的和，
   接着输出第2个和倒 数第2 个元素的和，以此类推  */ 

    vector<float> fvec{1.233, 23.13123, 4.2, 2.2, 3.3};
    
    
    // for(vector<float>::iterator iter1=fvec.begin(); iter1+1<fvec.end(); ++iter1){
    //     cout << *iter1 + *(iter1+1) << endl;
    // }

    for(auto iter1=fvec.begin(), iter2=fvec.end()-1; iter1==iter2; iter1++, iter2--){
        cout << *iter1 + *iter2 << endl;
    }











    // 作业 3.4 3.6 3.18 3.23
    // 3.4
    // string str1, str2;
	// cin >> str1 >> str2;
    // if (str1 == str2)
    //     cout << "The two strings are equal." << endl;
    // else
    //     cout << "The larger string is " << ((str1 > str2) ? str1 : str2);

    // 3.6
    // string s = "this is a string";
	// for (auto &x : s)
	// {
	// 	x = 'X';
	// }
	// cout << s << endl;

    // 3.18 
    // vector<int> ivec;
    // ivec.push_back(2);

    //3.23
    // vector<int> v(10, 1);
    // for (auto it=v.begin(); it!=v.end(); it++){
    //     *it *= 2;
    // }
    // for (auto one : v){
    //     cout << one <<endl;
    // }

    // 3.24
	// vector<int> ivec {1, 2, 4, 5};
	// int i;
	// while (cin >> i)
	// {
	// 	ivec.push_back(i);
	// }

	// for (auto it = ivec.rbegin(); it != ivec.rend() - 1; ++it)
	// {
	// 	cout << *it + *(it + 1) << endl;
	// }

	// //---------------------------------
	// cout << "---------------------------------" << endl;

	// auto it1 = ivec.begin();
	// auto it2 = ivec.end() - 1;
	// while (it1 <= it2)
	// {
    //     if(it1 == it2){
    //         cout << *it1 << endl;
    //         break;
    //     }
	// 	cout << *it1 + *it2 << endl;
	// 	++it1;
	// 	--it2;
	// }

    // int val1 = 12;
    // int val2 = 5;
    // cout << "val1/val2 = " << val1/val2 << endl;

    // vector<string> text {"qwer", "wasd", "not empty", "", "after an empty"};
    // // vector<string> text {};
    // if (!text.empty() && text[1] == "wasd"){
    //     cout << "the second string in this text is wasd" << endl;
    // }

    // const char *cp = "hello";
    // if (cp && *cp){
    //     cout << *cp << endl;
    // }

    // string s1 = "a string", *p = &s1;
    // int n = s1.size();
    // n = (*p).size(); // * has a priority greater than .
    // n = p->size();

    // unsigned long quiz1 = 0;    // 每一位代表一个学生是否通过考试
    // // 1UL << 12;  // 代表第12个学生通过
    // quiz1 |= (1UL << 12);   // 将第12个学生置为已通过
    // quiz1 &= ~(1UL << 12);  // 将第12个学生修改为未通过
    // bool stu12 = quiz1 & (1UL << 12);   // 判断第12个学生是否通过
}
