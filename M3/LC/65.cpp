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

TreeNode* buildNode(int val) {
    if (val == -1) {
        return nullptr;
    }
    return new TreeNode(val);
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
        auto* left = buildNode(*it++);
        auto* right = buildNode(*it++);
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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    auto* n = root;
    auto* v = new TreeNode(val);
    if (!n) {
        return v;
    }
    TreeNode* p = nullptr;
    while (n) {
        p = n;
        if (val < n->val) {
            n = n->left;
        } else {
            n = n->right;
        }
    }
    if (val < p->val) {
        p->left = v;
    } else {
        p->right = v;
    }
    return root;
}

//https://leetcode.cn/problems/insert-into-a-binary-search-tree/
int main() {
    auto* node = buildTree({10, 6, 14, 2, 8, 12, 16});
    insertIntoBST(node, 9);
    node = buildTree({10, 6, 14, 2, 8, 12, 16});
    insertIntoBST(node, 7);
    node = buildTree({10, 6, 14, 2, 8, 12, 16});
    insertIntoBST(node, 5);
    node = buildTree({10, 6, 14, 2, 8, 12, 16});
    insertIntoBST(node, 1);
    node = buildTree({10, 6, 14, 2, 8, 12, 16});
    insertIntoBST(node, 11);
    node = buildTree({10, 6, 14, 2, 8, 12, 16});
    insertIntoBST(node, 13);
    node = buildTree({10, 6, 14, 2, 8, 12, 16});
    insertIntoBST(node, 15);
    node = buildTree({10, 6, 14, 2, 8, 12, 16});
    insertIntoBST(node, 17);
}