//
// Created by PC on 2025/10/21.
//

#include <iostream>
#include <vector>
using std::vector;

//时间复杂度O(n) 空间复杂度O(n)
int minCostClimbingStairs(const vector<int>& cost) {
    //dp[i]: 到达第i + 1阶的最小花费
    int dp[cost.size() + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= cost.size(); ++i) {
        dp[i] = std::min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }
    return dp[cost.size()];
}

int main() {
    std::cout << minCostClimbingStairs({10,15,20}) << std::endl;
    std::cout << minCostClimbingStairs({1,100,1,1,1,100,1,1,100,1}) << std::endl;
}