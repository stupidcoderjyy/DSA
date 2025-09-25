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

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) {
        return nullptr;
    }
    if (!root->left && !root->right) {
        return root->val >= low && root->val <= high ? root : nullptr;
    }
    if (root->val < low) {
        return trimBST(root->right, low, high);
    }
    if (root->val > high) {
        return trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, root->val);
    root->right = trimBST(root->right, root->val, high);
    return root;
}

//https://leetcode.cn/problems/trim-a-binary-search-tree/
int main() {
    auto* node = buildTree({5,3,7,2,4,6,8});
    auto* result = trimBST(node, 6, 8);
    node = buildTree({5,3,7,2,4,6,8});
    result = trimBST(node, 3,7);
    node = buildTree({5,3,7,2,4,6,8});
    result = trimBST(node, 2, 4);
    node = buildTree({5,3,7,2,4,6,8});
    result = trimBST(node, 10, 12);
    node = buildTree({5,3,7,2,4,6,8});
    result = trimBST(node, -5, -1);
    node = buildTree({5,3,7,2,4,6,8});
    result = trimBST(node, 5, 5);
    node = buildTree({5,3,7,2,-1,-1,8});
    result = trimBST(node, 2,6);
}