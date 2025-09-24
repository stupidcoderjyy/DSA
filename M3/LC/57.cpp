//
// Created by PC on 2025/9/23.
//

#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <vector>
//
// Created by PC on 2025/9/22.
//
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left{}, *right{};
    TreeNode(): val() {}
    explicit TreeNode(int val): val(val) {}
};

int findLargest(vector<int>& nums, int i, int j) {
    int k = i;
    for (int max = INT_MIN ; i <= j ; i++) {
        if (nums[i] > max) {
            max = nums[i];
            k = i;
        }
    }
    return k;
}

TreeNode* build(vector<int>& nums, int i, int j) {
    if (i > j) {
        return nullptr;
    }
    int m = findLargest(nums, i, j);
    auto* node = new TreeNode(nums[m]);
    node->left = build(nums, i, m - 1);
    node->right = build(nums, m + 1, j);
    return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(nums, 0, nums.size() - 1);
}

//https://leetcode.cn/problems/maximum-binary-tree/description/
int main() {
    vector<int> nums = {};
    auto* node = constructMaximumBinaryTree(nums);
    nums = {1,2};
    node = constructMaximumBinaryTree(nums);
    nums = {1,3,2};
    node = constructMaximumBinaryTree(nums);
    nums = {1,2,5,4,3};
    node = constructMaximumBinaryTree(nums);
}