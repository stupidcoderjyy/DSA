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
int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int hl = maxDepth(root->left);
    int hr = maxDepth(root->right);
    return std::max(hl, hr) + 1;
}