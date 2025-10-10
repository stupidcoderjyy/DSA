
#include <iostream>

//时间复杂度：O(n/l) l为data数组长度 空间复杂度：O(n)
struct Node {
public:
    int key;
    Node* next, *prev;
    Node(): key(), next(), prev() {}
    explicit Node(int key): key(key), next(), prev() {}
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

class MyHashSet {
public:
    MyHashSet() = default;

    void add(int key) {
        Node* n;
        if (!locate(key, n)) {
            insert_node(n, new Node(key));
        }
    }
    
    void remove(int key) {
        Node* n;
        if (locate(key, n)) {
            remove_node(n);
            delete n;
        }
    }
    
    bool contains(int key) {
        Node* n;
        return locate(key, n);
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
    MyHashSet set;
    for (int i = 0; i < 6; i++) {
        set.add(i);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << set.contains(i);
    }
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        set.remove(i);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << set.contains(i);
    }
    std::cout << std::endl;
    for (int i = 3; i < 6; i++) {
        set.remove(i);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << set.contains(i);
    }
    std::cout << std::endl;
}