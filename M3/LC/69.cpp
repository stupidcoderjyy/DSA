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

void solve(TreeNode* n, int& sum) {
    if (!n) {
        return;
    }
    solve(n->right, sum);
    sum += n->val;
    n->val = sum;
    solve(n->left, sum);
}

TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    solve(root, sum);
    return root;
}

//https://leetcode.cn/problems/trim-a-binary-search-tree/
int main() {
    auto* node = buildTree({});
    convertBST(node);
    node = buildTree({2,1});
    convertBST(node);
    node = buildTree({5,3,7,2,4,6,8});
    convertBST(node);
    node = buildTree({5,3,-1,1});
    convertBST(node);
}