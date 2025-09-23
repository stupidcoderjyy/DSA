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

TreeNode* buildNode(string& s, string::iterator& it) {
    if (it == s.end()) {
        return nullptr;
    }
    auto ch = *it++;
    return ch == 'x' ? nullptr : new TreeNode(ch - '0');
}

TreeNode* buildTree(string s) {
    if (s.empty()) {
        return nullptr;
    }
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    deque<TreeNode*> deque;
    auto it = s.begin();
    auto* root = buildNode(s, it);
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

void solve(TreeNode* node, vector<string>& result, vector<int>& nums) {
    if (!node) {
        return;
    }
    nums.push_back(node->val);
    if (!node->left && !node->right) {
        auto it = nums.begin();
        string s = std::to_string(*it++);
        while (it != nums.end()) {
            s += "->" + std::to_string(*it++);
        }
        result.push_back(s);
    }
    solve(node->left, result, nums);
    solve(node->right, result, nums);
    nums.erase(nums.end());
}


vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    vector<int> nums;
    solve(root, result, nums);
    return result;
}

//https://leetcode.cn/problems/binary-tree-paths/description/
int main() {
    auto* root = buildTree("1 x2 xxx3");
    binaryTreePaths(root);
    root = buildTree("1");
    binaryTreePaths(root);
}