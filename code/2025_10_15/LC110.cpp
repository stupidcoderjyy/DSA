//
// Created by PC on 2025/10/16.
//

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
};

//时间复杂度O(N) 最差|最好|平均空间复杂度O(N)|O(logN)|O(logN)
bool isBalanced(TreeNode* node, int& maxDepth) {
    if (!node) {
        maxDepth = 0;
        return true;
    }
    int hl, hr;
    if (isBalanced(node->left, hl) && isBalanced(node->right, hr)) {
        maxDepth = std::max(hl, hr) + 1;
        return std::abs(hr - hl) <= 1;
    }
    return false;
}

bool isBalanced(TreeNode* root) {
    int maxDepth;
    return isBalanced(root, maxDepth);
}