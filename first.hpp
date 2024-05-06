#include <vector>
#include <iostream>
#include <stdexcept>

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
        int key;
        int value;
        bool occupied = false;  // 标记这个位置是否被占用
    };

    std::vector<HashNode> table;
    size_t capacity;

    size_t hashFunction(const int key) const {
        return std::hash<int>{}(key) % capacity;
    }

public:
    HashMap(size_t size) : capacity(size) {
        table.resize(capacity);
    }

    bool insert(const int key, const int value) {
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

    std::optional<int> find(const int key) const {
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

    bool update(const int key, const int newValue) {
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