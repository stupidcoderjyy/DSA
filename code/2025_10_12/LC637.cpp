//
// Created by PC on 2025/10/12.
//

#include <deque>
#include <iostream>
#include <vector>

using std::vector;
using std::deque;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
};

//时间复杂度O(N) 空间复杂度O(N)
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    deque<TreeNode*> nodes;
    nodes.push_back(root);
    while (!nodes.empty()) {
        int levelSize = nodes.size();
        long long sum = 0;
        for (int i = 0 ; i < levelSize ; i++) {
            auto* node = nodes.front();
            nodes.pop_front();
            sum += node->val;
            if (node->left) {
                nodes.push_back(node->left);
            }
            if (node->right) {
                nodes.push_back(node->right);
            }
        }
        result.push_back(static_cast<double>(sum) / levelSize);
    }
    return result;
}