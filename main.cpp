#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <optional>
#include <algorithm>

#include "first.hpp"

using namespace std;

struct Book{
    string name = {};
    int price = 0;
    // double discount = 0.0;
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

void printVectorInt(const vector<int> & vec){
    for(auto it=vec.begin(); it!=vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

char &getChar(string &str, int index){
    assert(str.size() > index);
    return str[index];
}

// 函数重载
vector<int> create_vector(int *list, int size){
    vector<int> vec;
    int *ptr = list;
    // *ptr and ptr
    for(int i=0;i<size;++i){
        // push_back(num) := 往当前vector的最后加入一个num值
        vec.push_back(*ptr);
        ptr++;
    }
    return vec;
}

vector<int> create_vector(int num, int size){
    vector<int> vec(size, num);
    return vec;
}

struct LinkList{ //结构体（类）
    int val;
    LinkList* next;

    // construct
    LinkList(int x) : val(x), next(nullptr) {}
};

LinkList* createLinkedList() {
    return nullptr; // 初始化为空指针，表示链表为空
}

void addAtHead(LinkList*& head, int val) {
    LinkList* newNode = new LinkList(val); // 创建新节点
    newNode->next = head; // 新节点指向原来的头节点
    head = newNode; // 更新头节点为新节点
}

void addAtTail(LinkList*& head, int val) {
    LinkList* newNode = new LinkList(val); // 创建新节点

    if (head == nullptr) {
        // 如果链表为空，新节点即为头节点
        head = newNode;
    } else {
        // 否则，遍历到链表末尾
        LinkList* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // 将新节点添加到最后
        temp->next = newNode;
    }
}

void addAtTailRecursive(LinkList* node, int val) {
    if (node->next == nullptr) {
        // 如果当前节点是最后一个节点，则在其后添加新节点
        node->next = new LinkList(val);
    } else {
        // 否则递归调用，移动到下一个节点
        addAtTailRecursive(node->next, val);
    }
}

void deleteLinkedList(LinkList*& head) {
    LinkList* current = head;
    while (current != nullptr) {
        LinkList* temp = current;
        current = current->next;
        delete temp;  // 释放当前节点的内存
    }
    head = nullptr; // 避免悬挂指针
}

void deleteLinkedListRecursive(LinkList*& node) {
    if (node == nullptr) {
        return;
    }
    deleteLinkedListRecursive(node->next); // 递归删除下一个节点
    delete node; // 删除当前节点
    node = nullptr;
}

// 定义一个find_char函数，要求返回某一字符在某一个字符串
// 中第一次出现的位置、以及出现的总次数
int find_char(const string& str, const char& c, int& occur){
    int firstOccur = -1;

    occur = 0;

    // 遍历整个字符串，检查每一位字符是否和c相等
    for(int i=0; i<str.size(); i++){
        if (str[i] == c){
            occur++;
            if(firstOccur == -1){
                firstOccur = i;
            }
        }
    }

    return firstOccur;
}
// 形参在函数被调用的时候初始化，形参初始化的值为实参

void printInt(int val, double val2){
    cout << val << endl;
    cout << val2 << endl;
}

// 没有默认值的参数放在参数列表的左边，有默认值的参数放在右边
void createWindow(string windowName, int width=600, int height=800){
    cout << "new window name: " << windowName << endl;
    cout << "new window's width: " << width << ", height: " << height << endl;
}

void createWindowwithHeight(string windowName, int height){
    createWindow(windowName, 600, height);
}

void createWindowwithOptional(string windowName, optional<int> width=600, optional<int> height=800){
    cout << "new window name: " << windowName << endl;
    cout << "new window's width: " << width.value_or(600) << ", height: " << height.value() << endl;
}

// function pointer
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b != 0)
        return static_cast<double>(a) / b;
    else
        return 0.0;  // case: divided by 0
}

// 递归实现阶乘
int fact(int n){
    if(n == 1){
        return 1;
    }

    // 循环/递归内容
    int result = n * fact(n-1);

    return result;
    // case: use loop
    // int result = 1;
    // for(int i=1; i<=n; i++){
    //     result *= i;
    // }
    // return result;
}

void func1(int* ptr){
    cout << *ptr << endl;
}

void foo(string** s){
    *s = new string("empty");
    cout << *s << endl;
}

void foo2(string*& s){
    s = new string("occupied");
    cout << *s << endl;
}

void bar(string* s){
    cout << *s << endl;
}

// 函数返回一个指向含有10个整数的数组的指针
int (*arrayFunc1(int index, int num)) [10]{
    static int arr[10];  // 静态数组
    
    arr[index] = num;
    
    return &arr;  // 返回数组的地址
}

auto arrayFunc2(int index, int num) -> int(*) [10]{
    static int arr[10];

    arr[index] = num;

    return &arr;
}

const int odd[] = {1,3,5};
const int even[] = {2,4,6};
decltype(odd) *arrPtr(int i){
    return (i%2) ? &odd : &even;
}

// 函数指针用于形参(callback function)
using Comparator = bool (*)(int, int);
// typedef bool (*Comparator)(int, int);

// use callback function to determine the order of sort
void sortVector(vector<int>& vec, Comparator comp){
    sort(vec.begin(), vec.end(), comp);
}

bool ascending(int a, int b){
    return a <= b;
}

bool descending(int a, int b){
    return a >= b;
}


auto printInt(int i) -> int{
    cout << i << endl;
    i++;
    return i;
}

// 函数返回一个指向含有10个整数的数组的指针, 并且修改该数组第index位的变量值为value
auto fooPtr(int index, int value) -> int(*) [10]{
    static int array[10];
    array[index] = value;
    return &array;
}

int main()
{
    // auto arrPtr = fooPtr(1, 2);
    // 返回类型 函数名(形参){
    // ......
    // 返回值 return xxx
    // }

    // 数组本质上就是指针
    // int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    // 指向数组元素的指针
    // 使用方式：通过 p1，可以访问和修改数组中的元素。p1[0] 等同于 arr[0]
    // 类型：int*
    // int *p1 = arr;

    // 指向整个数组的指针
    // 使用方式：不能直接通过 p2 来访问数组的元素，因为 p2 是指向整个数组的。要访问数组元素，需要先解引用 p2，然后使用索引。
    // e.g. (*p2)[1] 等同于 arr[1]。
    // 类型：int (*)[10]
    // int (*p2)[10] = &arr; 

    // int val = 3;
    // int *p3 = &val;
    // cout << p3[0] << endl;

    // 类型别名
    // typedef double hour;
    // hour current = 0.0;
    // typedef int arr10[10];
    // arr10 arr2 = {2,3,4,5,6};
    // arr10* p4 = &arr2;
    // typedef int arrT[10];
    // arrT arr2 = {-1,-2,-3};
    // using arrT2 = int[10];
    // arrT2 arr3 = {2,4,6,8};
    // arrT* p4 = &arr2;
     
    // 声明一个返回数组指针类型的函数：
    // Type (*function_name(parameter_list)) [dimension]
    // int (*func(int i)) [10];
    // 拆解：
    // func(int i)表示调用func函数时需要一个int类型的形参
    // (*func(int i))意味着我们可以对函数调用的结果执行解引用操作
    // (*func(int i)) [10]表示解引用func的调用将得到一个大小是10的数组
    // int (*func(int i)) [10]表示数组中的元素是int类型

    // 尾置返回类型
    // auto func(int i) -> int(*) [10];

    // auto *p4 = &arr;
    // decltype(p2) p3 = &arr;

    // 使用decltype
    // const int odd[] = {1,3,5};
    // const int even[] = {2,4,6};
    // decltype(odd) *arrPtr(int i){
    //     return (i%2) ? &odd : &even;
    // }

    // int (*arr4)[10] = arrayFunc1(1, 99);
    // auto arr5 = arrayFunc2(2, -99);

    // inline function
    // string str_a = "aaa", str_b = "bB";
    // cout << isShorter(str_a, str_b);

    // function pointer 函数指针
    // 声明一个函数指针，指向接受两个int参数，并返回int的函数
    // int (*operation)(int, int) = nullptr;
    // int x = 4, y = 2;
    // char op = '*';

    // Book book_a("book a", 12, "novel");
    // Book book_b("book b", 34, "education");

    // if(op == '+'){
    //     operation = add;
    // }
    // else if(op == '-'){
    //     operation = subtract;
    // }
    // else if(op == '*'){
    //     operation = multiply;
    // }
    // else if(op == '/'){
    //     // invalid case
    //     // operation = divide;
    //     cout << "divide function has different return type, x/y = " << divide(x, y) << endl; 
    // }

    // if (operation != nullptr && op != '/'){
    //     cout << x << op << y << "=" << operation(x, y) << endl;
    // }

    vector<int> data = {21, 42, 11, -1, 0 , 99};
    vector<Book> bookData;
    // how to call sort function to sort a vector
    // sort(data.begin(), data.end());
    // sort(data.begin(), data.end(), ascending);
    sort(data.begin(), data.end(), descending);
    printVectorInt(data);


    // 返回值类型为引用或指针
    // 不要返回局部对象的引用或指针
    // linklist

    // 引用返回左值
    // string s = "a value";
    // cout << s << endl;
    // getChar(s, 0) = 'A';
    // cout << s << endl;

    // LinkList* myList = createLinkedList(); 
    // addAtHead(myList, 10); 
    // addAtHead(myList, 20); 
    // addAtTail(myList, 30); 
    // addAtTail(myList, 40); 
    // addAtTailRecursive(myList, 60);

    // LinkList* current = myList;
    // while (current != nullptr) {
    //     std::cout << current->val << " ";
    //     current = current->next;
    // }

    // deleteLinkedList(myList);

    cout << "end" << endl;
}
