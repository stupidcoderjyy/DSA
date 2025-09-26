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

bool solve(TreeNode* n, int& result, int& c) {
    if (!n) {
        return false;
    }
    if (--c == 0) {
        result = n->val;
        return true;
    }
    return solve(n->left, result, c) || solve(n->right, result, c);
}

int rg354(TreeNode* root, int k) {
    int result;
    solve(root, result, k);
    return result;
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    vector<int> vec;
    for (int i = 1 ; i <= 5 ; i++) {
        vec.push_back(i);
    }
    for (int i = 1 ; i <= 5 ; i++) {
        cout << rg354(buildTree(vec), i) << " ";
    }
    cout << endl;
    auto* n = buildTree({1,2,3,4,-1,-1,-1,5});
    for (int i = 1; i <= 5; ++i) {
        cout << rg354(n, i) << " ";
    }
    cout << endl;
    n = buildTree({1,2,3,4,5,-1,7});
    for (int i = 1; i <= 6; ++i) {
        cout << rg354(n, i) << " ";
    }
    cout << endl;
    n = buildTree({1,-1,3});
    for (int i = 1; i <= 2; ++i) {
        cout << rg354(n, i) << " ";
    }
    cout << endl;
}