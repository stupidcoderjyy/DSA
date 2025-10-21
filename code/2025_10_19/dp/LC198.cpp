//
// Created by PC on 2025/10/21.
//
#include <iostream>
#include <vector>

using std::vector;

//时间复杂度O(MN) 空间复杂度O(MN)
int Solve1(const vector<int>& nums) {
    //dp[1][i] 偷第i+1间房的最大收益
    //dp[0][i] 不偷偷第i+1间房的最大收益
    int dp[2][nums.size()];
    dp[0][0] = 0;
    dp[1][0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        //如果不偷这一间房，那么上一间房可偷可不偷
        dp[0][i] = std::max(dp[0][i - 1], dp[1][i - 1]);
        //如果偷这一间房，那么不能偷上一间房
        dp[1][i] = nums[i] + dp[0][i - 1];
    }
    return std::max(dp[0][nums.size() - 1], dp[1][nums.size() - 1]);
}

int Solve2(const vector<int>& nums) {
    //dp[i] 偷完i+1个房子后的最大收益
    int dp[nums.size()];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = std::max(dp[i - 1], nums[i] + (i > 1 ? dp[i - 2] : 0));
    }
    return dp[nums.size() - 1];
}

int rob(const vector<int>& nums) {
    return Solve2(nums);
}

int main() {
    std::cout << rob({1,2,3,1}) << std::endl;
    std::cout << rob({2,7,9,3,1}) << std::endl;
    std::cout << rob({10,15,20}) << std::endl;
    std::cout << rob({100,1,100,1,1,100}) << std::endl;
}