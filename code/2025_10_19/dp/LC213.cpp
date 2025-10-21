//
// Created by PC on 2025/10/21.
//
#include <iostream>
#include <vector>

using std::vector;

//时间复杂度O(N) 空间复杂度O(N)
int Solve1(const vector<int>& nums) {
    //dp[1][i] 偷第1间房情况下，偷完i+1个房子后的最大收益
    //dp[0][i] 不偷第1间房情况下，偷完i+1个房子后的最大收益
    if (nums.size() == 1) {
        return nums[0];
    }
    int dp[2][nums.size()];
    dp[0][0] = 0;
    dp[1][0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        dp[0][i] = std::max(dp[0][i - 1], nums[i] + (i > 1 ? dp[0][i - 2] : 0));
        dp[1][i] = std::max(dp[1][i - 1], nums[i] + (i > 1 ? dp[1][i - 2] : 0));
    }
    return std::max(dp[0][nums.size() - 1], dp[1][nums.size() - 2]);
}

int rob(const vector<int>& nums) {
    return Solve1(nums);
}

int main() {
    std::cout << rob({2,3,2}) << std::endl;
    std::cout << rob({1,2,3,1}) << std::endl;
    std::cout << rob({1,2,3}) << std::endl;
    std::cout << rob({5,2,3,6}) << std::endl;
}