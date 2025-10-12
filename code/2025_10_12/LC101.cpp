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
bool isSymmetric(TreeNode* na, TreeNode* nb) {
    if (!na && !nb) {
        return true;
    }
    if (na && nb && na->val == nb->val) {
        return isSymmetric(na->left, nb->right) && isSymmetric(na->right, nb->left);
    }
    return false;
}

bool isSymmetric(TreeNode* root) {
    return isSymmetric(root->left, root->right);
}