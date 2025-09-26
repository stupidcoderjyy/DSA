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

void solve(TreeNode* node, int& result, int& path) {
    if (!node) {
        return;
    }
    path += node->val;
    if (!node->left && !node->right) {
        result += path;
    }
    solve(node->left, result, path);
    solve(node->right, result, path);
    path -= node->val;
}


int rg362(TreeNode* root) {
    int result = 0, path = 0;
    solve(root, result, path);
    return result;
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    cout << rg362(buildTree({})) << endl;
    cout << rg362(buildTree({1})) << endl;
    cout << rg362(buildTree({1,2})) << endl;
    cout << rg362(buildTree({1,2,3,4})) << endl;
    cout << rg362(buildTree({1,2,-1,4})) << endl;
    cout << rg362(buildTree({1,-1,2,-1,-1,-1,3})) << endl;
    cout << rg362(buildTree({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1})) << endl;
}