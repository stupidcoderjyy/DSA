//
// Created by stupid_coder_jyy on 25-10-18.
//

#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>

using std::vector;
using std::deque;

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
int Solve(TreeNode* node, int& result) {
    if (!node) {
        return 0;
    }
    int left = Solve(node->left, result);
    int right = Solve(node->right, result);
    result = std::max(result, node->val + std::max(0, left) + std::max(0, right));
    //返回从当前结点出发的最大路径和
    return node->val + std::max(0, std::max(left, right));
}

int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    Solve(root, result);
    return result;
}

TreeNode* BuildNode(const vector<int>& vec, vector<int>::const_iterator& it) {
    if (it == vec.end()) {
        return nullptr;
    }
    int i = *it++;
    return i < -98 ? nullptr : new TreeNode(i);
}

TreeNode* BuildTree(const vector<int>& vec) {
    if (vec.empty()) {
        return nullptr;
    }
    deque<TreeNode*> deque;
    auto it = vec.begin();
    auto* root = new TreeNode(*it++);
    deque.push_front(root);
    while (it != vec.end()) {
        auto node = deque.back();
        deque.pop_back();
        auto* left = BuildNode(vec, it);
        auto* right = BuildNode(vec, it);
        deque.push_front(left);
        deque.push_front(right);
        if (!node) {
            continue;
        }
        node->left = left;
        node->right = right;
    }
    return root;
}

int main() {
    auto* n1 = BuildTree({9,6,-3,0,0,-6,2});
    auto* n2 = BuildTree({2,-6,-6});
    n1->right->right->left = n2;
    std::cout << maxPathSum(n1) << std::endl;
    std::cout << maxPathSum(BuildTree({-10,9,20,-99,-99,15,7})) << std::endl;
    std::cout << maxPathSum(BuildTree({6,-1,-2,9,-99,-99,3})) << std::endl;
    return 0;
}