//
// Created by PC on 2025/9/23.
//

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

TreeNode* buildNode(const vector<int>& vec, vector<int>::const_iterator& it) {
    if (it == vec.end()) {
        return nullptr;
    }
    int i = *it++;
    return i < 0 ? nullptr : new TreeNode(i);
}

TreeNode* buildTree(const vector<int>& vec) {
    if (vec.empty()) {
        return nullptr;
    }
    deque<TreeNode*> deque;
    auto it = vec.begin();
    auto* root = new TreeNode(*it++);
    deque.push_front(root);
    while (it != vec.end()) {
        auto node = deque.back();
        deque.pop_back();
        auto* left = buildNode(vec, it);
        auto* right = buildNode(vec, it);
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

void solve(TreeNode* n, TreeNode*& tail) {
    if (!n) {
        return;
    }
    if (!n->left && !n->right) {
        tail->right = n;
        tail = n;
        return;
    }
    solve(n->left, tail);
    solve(n->right, tail);
}

TreeNode* rg360(TreeNode* n) {
    TreeNode header;
    auto* tail = &header;
    solve(n, tail);
    return header.right;
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    auto result = rg360(buildTree({1}));
    result = rg360(buildTree({1,2,3}));
    result = rg360(buildTree({1,2,3,4}));
    result = rg360(buildTree({1,2,3,-1,4}));
    result = rg360(buildTree({1,2,3,-1,-1,4}));
    result = rg360(buildTree({1,2,3,-1,-1,-1,4}));
}