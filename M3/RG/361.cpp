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

void solve(TreeNode* n, TreeNode*& tail) {
    if (!n) {
        return;
    }
    if (!n->left && !n->right) {
        tail->right = n;
        tail = n;
        return;
    }
    solve(n->left, tail);
    solve(n->right, tail);
}

bool rg361(TreeNode* n1, TreeNode* n2) {
    if (!n1 && !n2) {
        return true;
    }
    if (!n1 || !n2) {
        return false;
    }
    return rg361(n1->left, n2->left) && rg361(n1->right, n2->right);
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    cout << rg361(buildTree({}), buildTree({})) << endl;
    cout << rg361(buildTree({1}), buildTree({1})) << endl;
    cout << rg361(buildTree({}), buildTree({1})) << endl;
    cout << rg361(buildTree({1}), buildTree({})) << endl;
    cout << rg361(buildTree({1,2}), buildTree({1,2})) << endl;
    cout << rg361(buildTree({1,-1}), buildTree({1,2})) << endl;
    cout << rg361(buildTree({1,2}), buildTree({1,-1})) << endl;
    cout << rg361(buildTree({1,2,3}), buildTree({1,2,3,4})) << endl;
}