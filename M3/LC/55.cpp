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
    int val = preorder[r2];
    auto* node = new TreeNode(val);
    int i = valToIndex[val];
    int j = l2 + i - l1;
    node->left = build(inorder, preorder, l1, i - 1, l2, j - 1);
    node->right = build(inorder, preorder, i + 1, r1, j, r2 - 1);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for (int i = 0 ; i < inorder.size() ; i++) {
        valToIndex[inorder[i]] = i;
    }
    return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

//https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
int main() {
    vector inorder = {1}, postorder = {1};
    auto* node = buildTree(inorder, postorder);
    inorder = {2,1}, postorder = {2,1};
    node = buildTree(inorder, postorder);
    inorder = {2,1,3}, postorder = {2,3,1};
    node = buildTree(inorder, postorder);
    inorder = {4,2,1,3}, postorder = {4,2,3,1};
    node = buildTree(inorder, postorder);
    inorder = {4,2,1,3,5}, postorder = {4,2,5,3,1};
    node = buildTree(inorder, postorder);
}