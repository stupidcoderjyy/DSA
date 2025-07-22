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
    bool hasPrev{}, hasNext{};
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
    while (it != s.end()) {
        auto node = deque.back();
        deque.pop_back();
        auto* left = buildNode(s, it);
        auto* right = buildNode(s, it);
        deque.push_front(left);
        deque.push_front(right);
        if (!node) {
            continue;
        }
        node->lChild = left;
        node->rChild = right;
    }
    return root;
}

void inThreadTree(Node* node, Node*& prev) {
    if (!node) {
        return;
    }
    inThreadTree(node->lChild, prev);
    //设置前驱
    if (!node->lChild) {
        node->lChild = prev;
        node->hasPrev = true;
    }
    //设置后继
    if (!node->rChild) {
        node->hasNext = true;
    }
    if (prev && prev->hasNext) {
        prev->rChild = node;
    }
    prev = node;
    inThreadTree(node->rChild, prev);
}

Node* firstNode(Node* p) {
    if (!p) {
        return nullptr;
    }
    //最左侧的，没有左子树的结点
    while (!p->hasPrev) {
        p = p->lChild;
    }
    return p;
}

Node* nextNode(Node* p) {
    //一定是右子树的第一个结点
    return p->hasNext ? p->rChild : firstNode(p->rChild);
}

Node* lastNode(Node* p) {
    //最右侧的，没有右子树的结点
    while (!p->hasNext) {
        p = p->rChild;
    }
    return p;
}

Node* prevNode(Node* p) {
    //一定是左子树的最后一个结点
    return p->hasPrev ? p->lChild : lastNode(p->lChild);
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