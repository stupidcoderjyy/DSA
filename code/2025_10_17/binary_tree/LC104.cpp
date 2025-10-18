//
// Created by stupid_coder_jyy on 25-10-18.
//
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
};

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int hl = maxDepth(root->left);
    int hr = maxDepth(root->right);
    return std::max(hl, hr) + 1;
}