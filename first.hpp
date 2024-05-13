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


class HashMap {
private:
    struct HashNode {
        string key;
        int value;
        bool occupied = false;  // 标记这个位置是否被占用
    };

    std::vector<HashNode> table;
    size_t capacity;

    size_t hashFunction(const string& key) const {
        return std::hash<string>{}(key) % capacity;
    }

public:
    HashMap(size_t size) : capacity(size) {
        table.resize(capacity);
    }

    bool insert(const string& key, const int value) {
        size_t idx = hashFunction(key);
        size_t start_idx = idx;
        do {
            if (!table[idx].occupied) {
                table[idx] = {key, value, true};
                return true;
            }
            idx = (idx + 1) % capacity;
        } while (idx != start_idx);  // 防止无限循环

        return false;  // 表已满
    }

    std::optional<int> find(const string& key) const {
        size_t idx = hashFunction(key);
        size_t start_idx = idx;
        do {
            if (table[idx].occupied && table[idx].key == key) {
                return table[idx].value;
            }
            idx = (idx + 1) % capacity;
        } while (idx != start_idx && table[idx].occupied);

        return {};  // 没找到
    }

    bool update(const string& key, const int newValue) {
        size_t idx = hashFunction(key);
        size_t start_idx = idx;
        do {
            if (table[idx].occupied && table[idx].key == key) {
                table[idx].value = newValue;
                return true;
            }
            idx = (idx + 1) % capacity;
        } while (idx != start_idx && table[idx].occupied);

        return false;  // 键不存在
    }
};

class TreeNode {
public:
    int value;          // 节点存储的数据
    TreeNode* left;     // 指向左子节点的指针
    TreeNode* right;    // 指向右子节点的指针

    // 构造函数
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // helper function
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool find(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (value == node->value) {
            return true;
        } else if (value < node->value) {
            return find(node->left, value);
        } else {
            return find(node->right, value);
        }
    }

    TreeNode* remove(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value > node->value) {
            node->right = remove(node->right, value);
        } else {
            // 找到了要删除的节点
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // 节点有两个子节点：用右子树的最小值节点替换当前节点
            TreeNode* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }

    // 辅助函数：找到给定树中的最小值节点
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->value << " ";
            inorder(node->right);
        }
    }

public:
    // 构造函数
    BinaryTree() : root(nullptr) {}

    // 插入节点
    void insert(int value) {
        root = insert(root, value);
    }

    bool find(int value) {
        return find(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    // 中序遍历
    void inorderTraversal() {
        inorder(root);
        std::cout << std::endl;
    }
};