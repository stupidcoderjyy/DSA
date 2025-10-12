//
// Created by PC on 2025/10/12.
//

#include <vector>
#include <deque>

using std::vector;
using std::deque;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    deque<TreeNode*> nodes;
    nodes.push_back(root);
    while (!nodes.empty()) {
        vector<int> level;
        int levelSize = nodes.size();
        for (int i = 0 ; i < levelSize ; i++) {
            auto* node = nodes.front();
            nodes.pop_front();
            level.push_back(node->val);
            if (node->left) {
                nodes.push_back(node->left);
            }
            if (node->right) {
                nodes.push_back(node->right);
            }
        }
        result.push_back(level);
    }
    return result;
}