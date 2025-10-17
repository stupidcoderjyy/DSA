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

//时间复杂度O(M+N) 最差|最好|平均空间复杂度O(max(M,N))|O(log(max(M,N)))|O(log(max(M,N))))
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1) {
        if (root2) {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        }
        return root1;
    }
    return root2;
}