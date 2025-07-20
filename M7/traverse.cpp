//
// Created by PC on 25-7-20.
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

void preOrder(const Node* node) {
    if (node) {
        cout << node->val << " ";
        preOrder(node->lChild);
        preOrder(node->rChild);
    }
}

void inOrder(const Node* node) {
    if (node) {
        inOrder(node->lChild);
        cout << node->val << " ";
        inOrder(node->rChild);
    }
}

void postOrder(const Node* node) {
    if (node) {
        postOrder(node->lChild);
        postOrder(node->rChild);
        cout << node->val << " ";
    }
}

void traverse(const Node* node) {
    cout << "preOrder:\t";
    preOrder(node);
    cout << endl;
    cout << "inOrder:\t";
    inOrder(node);
    cout << endl;
    cout << "postOrder:\t";
    postOrder(node);
    cout << endl;
}

int main() {
    auto* root = buildTree("1 23 x4x5 xx6");
    traverse(root);
}