//
// Created by PC on 2025/10/12.
//

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
};

int IsFull(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int ld = 0;
    int rd = 0;
    for (auto* node = root; node; node = node->left, ld++) {}
    for (auto* node = root; node; node = node->right, rd++) {}
    return ld == rd ? ld : -1;
}

//时间复杂度O(logN * logN) 空间复杂度O(logN)
int countNodes(TreeNode* root) {
    int full = IsFull(root);
    if (full >= 0) {
        return (1 << full) - 1;
    }
    //一定有一个子树是满二叉树
    return 1 + countNodes(root->left) + countNodes(root->right);
}