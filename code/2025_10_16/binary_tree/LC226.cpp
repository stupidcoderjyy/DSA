//
// Created by PC on 2025/10/17.
//

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
};

//时间复杂度O(N) 最差|最好|平均空间复杂度O(N)|O(logN)|O(logN)
void Invert(TreeNode* node) {
    if (!node) {
        return;
    }
    Invert(node->left);
    Invert(node->right);
    auto* l = node->left;
    node->left = node->right;
    node->right = l;
}

TreeNode* invertTree(TreeNode* root) {
    Invert(root);
    return root;
}