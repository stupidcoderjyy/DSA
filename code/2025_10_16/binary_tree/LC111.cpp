//
// Created by PC on 2025/10/17.
//

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
};

//时间复杂度O(N) 最差|最好|平均空间复杂度O(N)|O(logN)|O(logN)
int Solve(TreeNode* root) {
    if (!root->left) {
        return 1 + (root->right ? Solve(root->right) : 0);
    }
    if (!root->right) {
        return 1 + Solve(root->left);
    }
    return 1 + std::min(Solve(root->left), Solve(root->right));
}

int minDepth(TreeNode* root) {
    return root ? Solve(root) : 0;
}