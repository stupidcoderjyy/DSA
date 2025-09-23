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

int isFull(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int ld = 0;
    int rd = 0;
    for (auto* node = root ; node ; node = node->left, ld++) {}
    for (auto* node = root ; node ; node = node->right, rd++) {}
    return ld == rd ? ld : -1;
}

int countNodes(TreeNode* root) {
    int full = isFull(root);
    if (full >= 0) {
        return (1 << full) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//https://leetcode.cn/problems/count-complete-tree-nodes/description/
int main() {
    auto* root = buildTree("1 23 4567 89123");
    cout << countNodes(root) << endl;
    root = buildTree("1");
    cout << countNodes(root) << endl;
    root = buildTree("");
    cout << countNodes(root) << endl;
}