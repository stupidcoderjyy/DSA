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

unordered_map<int, int> valToIndex;

TreeNode* build(vector<int>& inorder, vector<int>& preorder, int l1, int r1, int l2, int r2) {
    if (l1 > r1) {
        return nullptr;
    }
    int val = preorder[l2];
    auto* node = new TreeNode(val);
    int i = valToIndex[val];
    int j = l2 + i - l1;
    node->left = build(inorder, preorder, l1, i - 1, l2 + 1, j);
    node->right = build(inorder, preorder, i + 1, r1, j + 1, r2);
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0 ; i < inorder.size() ; i++) {
        valToIndex[inorder[i]] = i;
    }
    return build(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
}

//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
int main() {
    vector inorder = {1}, preorder = {1};
    auto* node = buildTree(preorder, inorder);
    inorder = {2,1}, preorder = {1,2};
    node = buildTree(preorder, inorder);
    inorder = {2,1,3}, preorder = {1,2,3};
    node = buildTree(preorder, inorder);
    inorder = {4,2,1,3}, preorder = {1,2,4,3};
    node = buildTree(preorder, inorder);
    inorder = {4,2,1,3,5}, preorder = {1,2,4,3,5};
    node = buildTree(preorder, inorder);
}