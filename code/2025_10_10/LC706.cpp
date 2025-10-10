
#include <iostream>

//时间复杂度：O(n/l) l为data数组长度 空间复杂度：O(n)
struct Node {
public:
    int key, val;
    Node* next, *prev;
    Node(): key(), val(), next(), prev() {}
    explicit Node(int key, int val): key(key), val(val), next(), prev() {}
};

void insert_node(Node* parent, Node* node) {
    auto* new_next = parent->next;
    node->next = new_next;
    parent->next = node;
    node->prev = parent;
    if (new_next) {
        new_next->prev = node;
    }
}

void remove_node(const Node* node) {
    if (node->prev) {
        node->prev->next = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
}

#define LEN 128

class MyHashMap {
public:
    MyHashMap() = default;

    void put(int key, int val) {
        Node* n;
        if (locate(key, n)) {
            n->val = val;
        } else {
            insert_node(n, new Node(key, val));
        }
    }
    
    void remove(int key) {
        Node* n;
        if (locate(key, n)) {
            remove_node(n);
            delete n;
        }
    }
    
    int get(int key) {
        Node* n;
        if (locate(key, n)) {
            return n->val;
        }
        return -1;
    }
private:
    Node data[LEN];

    bool locate(int key, Node*& node) {
        int hash = key % LEN;
        node = &data[hash];
        while (node->next) {
            node = node->next;
            if (node->key == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    MyHashMap set;
    set.put(1, 1);
    std::cout << set.get(1) << '\n';
    set.put(1, 2);
    std::cout << set.get(1) << '\n';
    set.remove(1);
    std::cout << set.get(1) << '\n';
}