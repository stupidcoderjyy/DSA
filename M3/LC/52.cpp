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

int sum(TreeNode* node) {
    if (!node) {
        return 0;
    }
    int s = sum(node->left) + sum(node->right);
    if (node->left && !node->left->left && !node->left->right) {
        s += node->left->val;
    }
    return s;
}


int sumOfLeftLeaves(TreeNode* root) {
    return sum(root);
}

//https://leetcode.cn/problems/sum-of-left-leaves/description/
int main() {
    // auto* root = buildTree("1 23 45x8 xx67xx9x");
    auto* root = buildTree("1");
    cout << sumOfLeftLeaves(root) << endl;
}