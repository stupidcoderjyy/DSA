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


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto* node = root;
    while (node) {
        if (p->val < node->val && q->val < node->val) {
            node = node->left;
        } else if (p->val > node->val && q->val > node->val) {
            node = node->right;
        } else {
            break;
        }
    }
    return node;
}

//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
int main() {
    auto* node = buildTree("12");
    cout << lowestCommonAncestor(node, node, node->left)->val - 1 << endl;
    node = buildTree("213");
    cout << lowestCommonAncestor(node, node->left, node->right)->val - 2 << endl;
    node = buildTree("5 47 xx68");
    cout << lowestCommonAncestor(node, node->left, node->right)->val - 5 << endl;
    cout << lowestCommonAncestor(node, node->right->right, node->right)->val - 7 << endl;
    cout << lowestCommonAncestor(node, node->right->left, node->right->right)->val - 7 << endl;
    cout << lowestCommonAncestor(node, node, node->right->left)->val - 5 << endl;
}