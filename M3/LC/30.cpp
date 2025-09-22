#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
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

void traverse(TreeNode* node, vector<int>& vec) {
    if (!node) {
        return;
    }
    traverse(node->left, vec);
    traverse(node->right, vec);
    vec.push_back(node->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vec;
    traverse(root, vec);
    return vec;
}

//https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
int main() {
    auto* root = buildTree("1x2xx3x");
    auto vec = postorderTraversal(root);
    for (int i : vec) {
        cout << (char)i << endl;
    }
}