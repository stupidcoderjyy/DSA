//
// Created by PC on 2025/10/12.
//

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
};

//时间复杂度O(N) 空间复杂度O(N) (系统栈)
int sum(TreeNode* node) {
    if (!node) {
        return 0;
    }
    int s = sum(node->left) + sum(node->right);
    if (node->left && !node->left->left && !node->left->right) {
        s += node->left->val;
    }
    return s;
}


int sumOfLeftLeaves(TreeNode* root) {
    return sum(root);
}