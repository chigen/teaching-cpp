#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>

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

void foo(){

    // string *str = new string temp("empty");
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

int main()
{
    // 返回类型 函数名(形参){
    // ......

    // 返回值 return xxx
    // }

    
    // fact(5);

    // int a = 2;
    // double b = 2.2;
    // printInt(a, b);

    // 定义一个find_char函数，要求返回某一字符在某一个字符串
    // 中第一次出现的位置、以及出现的总次数
    // string str = "hello world";
    // char c = 'l';
    // int occur1 = 0;
    // int firstOccur1 = find_char(str, c, occur1);
    // cout << "first occur: " << firstOccur1 << " occur count: " << occur1 << endl;


    // string str2 = "qwer";
    // char key = 'e';
    // firstOccur1 = find_char(str2, key, occur1);
    // cout << "first occur: " << firstOccur1 << " occur count: " << occur1 << endl;

    // const形参和实参 & 常量引用


    // const string& s2;
    // s2 = foo();

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

    LinkList* myList = createLinkedList(); 
    addAtHead(myList, 10); 
    addAtHead(myList, 20); 
    addAtTail(myList, 30); 
    addAtTail(myList, 40); 
    addAtTailRecursive(myList, 60);

    // LinkList* current = myList;
    // while (current != nullptr) {
    //     std::cout << current->val << " ";
    //     current = current->next;
    // }

    // deleteLinkedList(myList);
    cout << "end" << endl;
}
