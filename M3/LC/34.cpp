#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
//
// Created by PC on 2025/9/22.
//
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left{}, *right{};
    TreeNode(): val() {}
    explicit TreeNode(int val): val(val) {}
};

TreeNode* buildNode(string& s, string::iterator& it) {
    if (it == s.end()) {
        return nullptr;
    }
    auto ch = *it++;
    return ch == 'x' ? nullptr : new TreeNode(ch);
}

TreeNode* buildTree(string s) {
    if (s.empty()) {
        return nullptr;
    }
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    deque<TreeNode*> deque;
    auto it = s.begin();
    auto* root = new TreeNode(*it++);
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
        node->left = left;
        node->right = right;
    }
    return root;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> vec;
    stack<TreeNode*> nodes;
    stack<bool> isLeft;
    nodes.push(root);
    isLeft.push(false);
    while (true) {
        while (nodes.top()) {
            nodes.push(nodes.top()->left);
            isLeft.push(true);
        }
        while (true) {
            auto isLeftChild = isLeft.top();
            nodes.pop();
            isLeft.pop();
            if (nodes.empty()) {
                return vec;
            }
            if (isLeftChild) {
                vec.push_back(nodes.top()->val);
                nodes.push(nodes.top()->right);
                isLeft.push(false);
                break;
            }
        }
    }
}

//https://leetcode.cn/problems/binary-tree-inorder-traversal/
int main() {
    // auto* root = buildTree("1 23 45x8 xx67xx9x");
    auto* root = buildTree("1x2xx3");
    auto vec = inorderTraversal(root);
    for (int i : vec) {
        cout << (char)i << endl;
    }
}