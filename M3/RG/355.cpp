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

TreeNode* solve(TreeNode* n, int x, bool search) {
    if (!n) {
        return nullptr;
    }
    if (n->val == x) {
        search = false;
    }
    n->left = solve(n->left, x, search);
    n->right = solve(n->right, x, search);
    if (!search) {
        delete n;
        return nullptr;
    }
    return n;
}

TreeNode* rg355(TreeNode* root, int x) {
    return solve(root, x, true);
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    auto* node = buildTree({1,2,3,4,5,6,7});
    auto* result = rg355(node, 1);
    node = buildTree({1,2,3,4,5,6,7});
    result = rg355(node, 2);
    node = buildTree({1,2,3,4,5,6,7});
    result = rg355(node, 3);
    node = buildTree({1,2,3,4,5,6,7});
    result = rg355(node, 4);
    node = buildTree({1,2,3,4,5,6,7});
    result = rg355(node, 5);
    node = buildTree({1,2,3,4,5,6,7});
    result = rg355(node, 7);
}