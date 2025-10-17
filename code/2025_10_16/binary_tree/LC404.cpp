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
int Sum(TreeNode* node) {
    if (!node) {
        return 0;
    }
    int s = Sum(node->left) + Sum(node->right);
    if (node->left && !node->left->left && !node->left->right) {
        s += node->left->val;
    }
    return s;
}

int sumOfLeftLeaves(TreeNode* root) {
    return Sum(root);
}