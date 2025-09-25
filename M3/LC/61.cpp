//
// Created by PC on 2025/9/23.
//

#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
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

void solve(TreeNode* node, TreeNode*& prev, int& min) {
    if (!node) {
        return;
    }
    solve(node->left, prev, min);
    if (prev) {
        min = std::min(min, node->val - prev->val);
    }
    prev = node;
    solve(node->right, prev, min);
}

int getMinimumDifference(TreeNode* root) {
    int min = INT_MAX;
    TreeNode* prev = nullptr;
    solve(root, prev, min);
    return min;
}

//https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
int main() {
    auto* node = buildTree("1x2");
    cout << getMinimumDifference(node) << endl;
    node = buildTree("2 16");
    cout << getMinimumDifference(node) << endl;
    node = buildTree("5 37 1xx9");
    cout << getMinimumDifference(node) << endl;
}