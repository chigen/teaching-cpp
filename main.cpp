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



class Box
{
    public:
        // 构造函数
        Box();
        Box(double len, double wid, double hei);
        // 成员函数声明
        double getVolume();
        void set(double len, double wid, double hei);
        double getLength();
        double getWidth();
        double getHeight();
        void setHeight(double h);
    private:
        // 成员变量声明   
        double length;   
        double width; 
        double height;   
};

double Box::getLength(){
    return length;
}

double Box::getWidth(){
    return width;
}

double Box::getHeight(){
    return height;
}

void Box::setHeight(double h){
    height = h;
}

// 成员函数定义
double Box::getVolume(){
    return length * width * height;
}

Box::Box(){
    // implement it
    height = 1.0;
    width = 1.0;
    length = 1.0;
}

Box::Box(double len, double wid, double hei){
    // implement it
    height = hei;
    length = len;
    width = wid;
}

void Box::set( double len, double wid, double hei)
{
    length = len;
    width = wid;
    height = hei;
}

int main()
{
    // 常数阶O(1)
    // int i = 1;
    // int j = 2;
    // ++i;
    // j++;
    // int m = i + j;

    // 线性阶O(n)
    // for(int i=1, j=0; i<=5; ++i)
    // {
    //     j = i;
    //     j++;
    // }

    // 对数阶 O(logN)
    // int i = 1;
    // int n = 100;
    // while(i<n)
    // {
    //     i = i * 2;
    // }

    // 线性对数阶O(MlogN)
    // int m=100, n=1000;
    // for(m=1; m<n; m++)
    // {
    //     int i = 1;
    //     while(i<n)
    //     {
    //         i = i * 2;
    //     }
    // }

    Box box1;
    box1.set(1.0, 2.0, 1.0);
    cout << "this box's volume is " << box1.getVolume() << endl;

    cout << "end" << endl;
}
