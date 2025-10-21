//
// Created by PC on 2025/10/21.
//

#include <iostream>

//时间复杂度O(n) 空间复杂度O(n)
int climbStairs(int n) {
    //dp[i]: 到达第i + 1阶的方法数
    int dp[std::max(2, n)];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n - 1];
}

int main() {
    for (int i = 1; i <= 4; ++i) {
        std::cout << climbStairs(i) << '\n';
    }
}