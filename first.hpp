#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <optional>

using namespace std;


// int fact(int val);

int sum(int n, vector<int> ivec);

inline bool isShorter (string &s1, string &s2){
    return s1.size() < s2.size();
}

void swap(int &a, int &b);


class IntStack {
private:
    std::vector<int> stack;  // 使用 vector 作为内部容器

public:
    // 向栈中添加元素（压栈）
    void push(int value) {
        stack.push_back(value);
    }

    // 从栈中移除元素（弹栈）
    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow");  // 当栈空时抛出异常
        }
        stack.pop_back();
    }

    // 获取栈顶元素
    int top() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");  // 当栈空时抛出异常
        }
        return stack.back();
    }

    // 检查栈是否为空
    bool isEmpty() const {
        return stack.empty();
    }

    // 获取栈的大小
    int size() const {
        return stack.size();
    }
};

class IntQueue {
private:
    std::vector<int> data;
    int start_index = 0;  // 队列头部的索引

public:
    // 入队操作
    void enqueue(int value) {
        data.push_back(value);
    }

    // 出队操作
    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        start_index++;  // 移动头部指针，而不是移动数据
    }

    // 查看队首元素
    int front() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[start_index];
    }

    // 检查队列是否为空
    bool isEmpty() const {
        return start_index >= data.size();
    }

    // 获取队列中的元素数量
    int size() const {
        return data.size() - start_index;
    }

    // 清理队列：移除已经出队的元素
    void cleanUp() {
        if (start_index > 0) {
            data.erase(data.begin(), data.begin() + start_index);
            start_index = 0;
        }
    }
};


struct HashNode {
    string key;
    int value;
    bool occupied = false;  // 标记这个位置是否被占用
};

class HashMap {
private:
    vector<HashNode> table;
    size_t capacity;

    // 通过key生成一个index
    size_t hashFunction(const string& key) const {
        return std::hash<string>{}(key) % capacity;
    }

public:
    HashMap(size_t size){
        capacity = size;
        table.resize(capacity);
    }

    bool insert(const string& key, const int value) {
        size_t index = hashFunction(key);
        size_t start_index = index;
        do {
            if(!table[index].occupied){
                HashNode node;
                node.key = key;
                node.value = value;
                node.occupied = true;
                table[index] = node;
                return true;
            }
            index = (index + 1) % capacity;
        } while (index != start_index);

        return false;
    }

    std::optional<int> find(const string& key) const {
        int idx = hashFunction(key);
        int start_idx = idx;
        do{
            // 如果找到了
            if(table[idx].occupied==true && key == table[idx].key){
                return table[idx].value;
            }
            idx = (idx + 1) % capacity;
        } while (idx != start_idx && table[idx].occupied==true);
        
        return {};
    }

    bool update(const string& key, const int newValue) {
        int idx = hashFunction(key);
        int start_idx = idx;
        do {
            if(table[idx].occupied==true && key == table[idx].key){
                table[idx].value = newValue;
                return true;
            }
            idx = (idx + 1) % capacity;
        } while (idx != start_idx && table[idx].occupied==true);

        return false; // 没找到
    }
};

class TreeNode {
public:
    int value;          // 节点存储的数据
    TreeNode* left;     // 指向左子节点的指针
    TreeNode* right;    // 指向右子节点的指针

    // 构造函数
    TreeNode(int val){
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    // helper function
    TreeNode* insert(TreeNode* node, int value) {
    }

    bool find(TreeNode* node, int value) {
    }

    TreeNode* remove(TreeNode* node, int value) {
    }

    // 辅助函数：找到给定树中的最小值节点
    TreeNode* minValueNode(TreeNode* node) {
    }

    void inorder(TreeNode* node) {
    }

public:
    // 构造函数
    BinaryTree(){
        root = nullptr;
    }

    // 构造函数2
    BinaryTree(int value){
        root = new TreeNode(value);
    }

    // 插入节点
    void insert(int value) {
        root = insert(root, value);
    }

    bool find(int value) {
        bool res = find(root, value);
        return res;
    }

    void remove(int value) {
        remove(root, value);
    }

    // 中序遍历
    void inorderTraversal() {
    }
};

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index != 0 && heap[parent(index)] > heap[index]) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int index) { return (index - 1) / 2; }
    int left(int index) { return 2 * index + 1; }
    int right(int index) { return 2 * index + 2; }

public:
    MinHeap() {}

    void insert(int element) {
        heap.push_back(element);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.size() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    void removeMin() {
        if (heap.size() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    bool isEmpty() const {
        return heap.empty();
    }
};