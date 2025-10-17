//
// Created by PC on 2025/10/17.
//

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

//时间复杂度O(N) 最差|最好|平均空间复杂度O(N)|O(logN)|O(logN)
bool findPath(TreeNode* node, int target) {
    if (!node->left && !node->right) {
        return target == node->val;
    }
    if (node->left && findPath(node->left, target - node->val)) {
        return true;
    }
    if (node->right && findPath(node->right, target - node->val)) {
        return true;
    }
    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    return root && findPath(root, targetSum);
}