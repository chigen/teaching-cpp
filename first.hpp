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
    // insert函数是递归函数，node代表递归时当前节点，value代表我们想插入的值
    TreeNode* insert(TreeNode* node, int value) {
        // 如果当前节点是空的(nullptr)，在此处插入我们的值
        if (node == nullptr){
            return new TreeNode(value);
        }
        // 比较当前节点的值和手上的值
        if(value < node->value){
            node->left = insert(node->left, value);
        }
        else{
            node->right = insert(node->right, value);
        }
        return node;
    }

    // find函数是递归函数，node代表递归时当前节点，value代表我们想查找的值
    bool find(TreeNode* node, int value) {
        if (node == nullptr){
            return false;
        }
        if (value == node->value){
            return true;
        }
        else if(value < node->value){
            bool result = find(node->left, value); 
            return result;
        }
        else {
            bool result = find(node->right, value); 
            return result;
        }
    }

    TreeNode* remove(TreeNode* node, int value) {
        if(value < node->value){
            // 要删除的节点在左手边
            node->left = remove(node->left, value);
        }
        else if (value > node->value){
            // 要删除的节点在右手边
            node->right = remove(node->right, value);
        }
        else{
            // 找到了要删除的节点
            if(node->left == nullptr){
                // 如果左手是空，那记录右手的子节点，让父节点指向该子节点
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr){
                // 如果右手是空，那记录左手的子节点，让父节点指向该子节点
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // 当前节点有两个子节点
            // 找当前节点的后继，返回后继节点的值
            TreeNode* right_successor = minValueNode(node->right);
            // 让当前节点的值等于后继节点的值
            node->value = right_successor->value;
            // 删除后继节点
            node->right = remove(node->right, right_successor->value);
        }
        return node;
    }

    // 辅助函数：找到给定树中的最小值节点
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* currentNode = node;
        while(currentNode!=nullptr && currentNode->left!=nullptr){
            currentNode = currentNode->left;
        }
        return currentNode;
    }

    // 递归函数
    void inorder(TreeNode* node) {
        if (node->left){
            inorder(node->left);
        }
        // 此时，当前节点没有左子树
        cout << node->value << " ";
        if (node->right){
            inorder(node->right);
        }
    }

    void preorder(TreeNode* node) {
        cout << node->value << " ";
        if (node->left){
            preorder(node->left);
        }
        // 此时，当前节点没有左子树
       
        if (node->right){
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node->left){
            postorder(node->left);
        }
        // 此时，当前节点没有左子树
        if (node->right){
            postorder(node->right);
        }
        cout << node->value << " ";
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
        inorder(root);
    }

    void preorderTraversal(){
        preorder(root);
    }

    void postorderTraversal() {
        postorder(root);
    }
};

void bubbleSort(vector<int> &vec);

//   0
//  1 2
// 3 4 5 6

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        // 对于一个新插入的值，该值的下表为index
        // 循环向上访问父节点，进行排序
        // 父节点下标parent(index)
        // 循环停止条件：1. index==0，2.heap[parent(index)] < heap[index]
        while(index != 0 && heap[index] < heap[parent(index)]){
            // 交换当前节点的值和父节点的值
            int temp = heap[index];
            heap[index] = heap[parent(index)];
            heap[parent(index)] = temp;
            // 更新下标
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        // 找出两个子节点的下标
        // 比较三个节点的大小，把最小的节点放在当前节点的位置
        // 如果当前节点的值最小，那么结束
        int leftChild = left(index);
        int rightChild = right(index);
        int smallest = index;

        if(leftChild < heap.size() && heap[leftChild] < heap[smallest]){
            smallest = leftChild;
        }
        if(rightChild < heap.size() && heap[rightChild] < heap[smallest]){
            smallest = rightChild;
        }
        if(smallest != index){
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
        // 把值插入至heap内
        heap.push_back(element);
        // 调用up函数对该值进行排序
        int len = heap.size();
        heapifyUp(len-1);
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