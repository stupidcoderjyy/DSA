#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>

struct Node {
    int key, value;
    Node* prev, *next;
    Node() : key(), value(), prev(), next() {}
    Node(int k, int v) : key(k), value(v), prev(), next() {}
};

void insert(Node* parent, Node* node) {
    auto* new_next = parent->next;
    node->next = new_next;
    parent->next = node;
    node->prev = parent;
    if (new_next) {
        new_next->prev = node;
    }
}

void remove(const Node* node) {
    if (node->prev) {
        node->prev->next = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
}

//维护一个双向链表，最新访问的值在头部，尾部就是需要被淘汰的值
class LRUCache {
public:
    explicit LRUCache(int capacity): capacity(capacity) {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        auto* n = head;
        while (n) {
            auto* next = n->next;
            delete n;
            n = next;
        }
    }

    int get(int key) {
        auto it = data.find(key);
        if (it == data.end()) {
            return -1;
        }
        auto* node = it->second;
        access_data(node);
        return node->value;
    }

    void put(int key, int value) {
        auto it = data.find(key);
        Node* node;
        if (it == data.end()) {
            if (data.size() == capacity) {
                expire_data();
            }
            node = new Node(key, value);
            data[key] = node;
        } else {
            node = it->second;
            node->value = value;
        }
        access_data(node);
    }
private:
    Node *head, *tail;
    int capacity;
    std::unordered_map<int, Node*> data;

    void access_data(Node* node) const {
        remove(node);
        insert(head, node);
    }

    void expire_data() {
        auto* node = tail->prev;
        data.erase(node->key);
        remove(node);
        delete node;
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    std::cout << cache.get(1) << '\n';
    cache.put(3,3);
    std::cout << cache.get(2) << '\n';
    cache.put(4,4);
    std::cout << cache.get(1) << '\n';
    std::cout << cache.get(3) << '\n';
    std::cout << cache.get(4) << '\n';
}