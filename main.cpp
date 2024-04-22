#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <optional>

#include "first.hpp"

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

void foo(string** s){
    delete s;
    *s = new string("empty");
    cout << *s << endl;
}

void foo2(string*& s){
    delete s;
    s = new string("occupied");
    cout << *s << endl;
}

void bar(string* s){
    cout << *s << endl;
}

char &getChar(string &str, int index){
    assert(str.size() > index);
    return str[index];
}

// 函数重载
vector<int> create_vector(int *list, int size){
    vector<int> vec;
    int *ptr = list;
    for(int i=0;i<size;++i){
        vec.push_back(*ptr);
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

int main()
{
    // 返回类型 函数名(形参){
    // ......

    // 返回值 return xxx
    // }

    
    // inline function
    // string str_a = "aaa", str_b = "bB";
    // cout << isShorter(str_a, str_b);

    // default parameter
    // createWindow("window1");
    // createWindow("window2", 1024);
    // createWindowwithHeight("window3", 1024);
    // createWindowwithOptional("window4", nullopt, 1024);

    // function pointer 函数指针
    // 声明一个函数指针，指向接受两个int参数，并返回int的函数
    // int (*operation)(int, int) = nullptr;
    // int x = 4, y = 2;
    // char op = '*';

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

    // 循环实现阶乘
    // 递归实现阶乘
    // fact(5);

    // int a = 2;
    // double b = 2.2;
    // printInt(a, b);

    // 引用和指针，不能指向一个在函数里面被定义的变量
    // 因为该变量会在函数结束时被销毁

    // 返回值类型为引用或指针
    // 不要返回局部对象的引用或指针
    // linklist

    // 引用返回左值
    // string s = "a value";
    // cout << s << endl;
    // getChar(s, 0) = 'A';
    // cout << s << endl;

    // 函数重载
    // int list[4] = {1, 2, 3, 4};
    // vector<int> vec1 = create_vector(list, 4);
    // for(int &num:vec1){
    //     cout << num << " ";
    // }
    // cout << endl;

    // vector<int> vec2 = create_vector(2, 5);
    // for(int &num:vec2){
    //     cout << num << " ";
    // }
    // cout << endl;

    string* s_foo = nullptr;
    foo(&s_foo);
    cout << "s_foo points to: "<<*s_foo<<endl;
    *s_foo = "first";
    cout << "s_foo points to: "<<*s_foo<<endl;
    foo2(s_foo);
    cout << "s_foo points to: "<<*s_foo<<endl;
    // bar(s_foo);

    delete s_foo;


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
