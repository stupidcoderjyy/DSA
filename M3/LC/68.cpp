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

TreeNode* solve(vector<int>& nums, int l, int r) {
    if (l > r) {
        return nullptr;
    }
    int m = (l + r) >> 1;
    auto* n = new TreeNode(nums[m]);
    n->left = solve(nums, l, m - 1);
    n->right = solve(nums, m + 1, r);
    return n;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return solve(nums, 0, nums.size() - 1);
}

//https://leetcode.cn/problems/trim-a-binary-search-tree/
int main() {
    TreeNode* n;
    vector<int> nums;
    nums = {};
    n = sortedArrayToBST(nums);
    nums = {1};
    n = sortedArrayToBST(nums);
    nums = {1,2};
    n = sortedArrayToBST(nums);
    nums = {1,2,3};
    n = sortedArrayToBST(nums);
    nums = {1,2,3,4};
    n = sortedArrayToBST(nums);
    nums = {1,2,3,4,5};
    n = sortedArrayToBST(nums);
    nums = {1,2,3,4,5,6};
    n = sortedArrayToBST(nums);
}