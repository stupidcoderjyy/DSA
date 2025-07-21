//
// Created by stupid_coder_jyy on 25-7-21.
//
#include <string>
#include <algorithm>
#include <deque>
#include <deque>
#include <iostream>
using namespace std;

struct Node {
    char val;
    Node *lChild{}, *rChild{};
    Node(): val() {}
    explicit Node(char val): val(val) {}
    bool lTag{}, rTag{};
};

Node* buildNode(string& s, string::iterator& it) {
    if (it == s.end()) {
        return nullptr;
    }
    auto ch = *it++;
    return ch == 'x' ? nullptr : new Node(ch);
}

Node* buildTree(string s) {
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    deque<Node*> deque;
    auto it = s.begin();
    auto* root = new Node(*it++);
    deque.push_front(root);
    while (!deque.empty()) {
        auto node = deque.back();
        deque.pop_back();
        auto* left = buildNode(s, it);
        auto* right = buildNode(s, it);
        if (!node) {
            continue;
        }
        node->lChild = left;
        node->rChild = right;
        deque.push_front(left);
        deque.push_front(right);
    }
    return root;
}

void inThreadTree(Node* node, Node*& pre) {
    if (!node) {
        return;
    }
    inThreadTree(node->lChild, pre);
    //设置前驱
    if (!node->lChild) {
        node->lChild = pre;
        node->lTag = true;
    }
    //设置后继
    if (pre && !pre->rChild) {
        pre->rChild = node;
        pre->rTag = true;
    }
    pre = node;
    inThreadTree(node->rChild, pre);
}

Node* firstNode(Node* p) {
    if (!p) {
        return nullptr;
    }
    while (!p->lTag) {
        p = p->lChild;
    }
    return p;
}

Node* nextNode(Node* p) {
    if (!p->rTag) {
        return firstNode(p->rChild);
    }
    return p->rChild;
}

Node* lastNode(Node* p) {
    while (!p->rTag) {
        p = p->rChild;
    }
    return p;
}

Node* prevNode(Node* p) {
    if (p->lTag) {
        return lastNode(p->lChild);
    }
    return p->lChild;
}

void inOrder(Node* root) {
    Node* p = firstNode(root);
    while (p) {
        cout << p->val << " ";
        p = nextNode(p);
    }
    cout << endl;
}

void inOrderReversed(Node* root) {
    Node* p = lastNode(root);
    while (p) {
        cout << p->val << " ";
        p = prevNode(p);
    }
    cout << endl;
}

int main() {
    Node* prev = nullptr, *root = buildTree("A BC xDE");
    inThreadTree(root, prev);
    inOrder(root);
    inOrderReversed(root);
}