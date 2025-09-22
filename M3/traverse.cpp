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

void levelOrder(Node* root) {
    deque<Node*> deque;
    deque.push_front(root);
    while (!deque.empty()) {
        auto* node = deque.back();
        deque.pop_back();
        cout << node->val << " ";
        if (node->lChild) {
            deque.push_front(node->lChild);
        }
        if (node->rChild) {
            deque.push_front(node->rChild);
        }
    }
}

void traverse(TreeNode* node) {
    cout << "preOrder:\t";
    preOrder(node);
    cout << endl;
    cout << "inOrder:\t";
    inOrder(node);
    cout << endl;
    cout << "postOrder:\t";
    postOrder(node);
    cout << endl;
    cout << "levelOrder:\t";
    levelOrder(node);
    cout << endl;
}

int main() {
    auto* root = buildTree("1 x2 xx3x xxxxx4");
    traverse(root);
}