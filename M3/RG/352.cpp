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

int rg352(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int c = root->left && root->right ? 1 : 0;
    c += rg352(root->left);
    c += rg352(root->right);
    return c;
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    vector<int> vec;
    cout << rg352(buildTree(vec)) << endl;
    for (int i = 1 ; i <= 20 ; i++) {
        vec.push_back(i);
        cout << rg352(buildTree(vec)) << endl;
    }
    cout << rg352(buildTree( {1,2,3,4,-1,-1,-1,5})) << endl;
    cout << rg352(buildTree( {1,2,3,-1,5,6,7})) << endl;
    cout << rg352(buildTree( {1,2,3,4,5,-1,7})) << endl;
    cout << rg352(buildTree( {1,-1,3})) << endl;
}