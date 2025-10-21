//
// Created by PC on 2025/10/21.
//

#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

//时间复杂度O(n) 空间复杂度O(n)
int maxProfit(const vector<int>& prices) {
    //dp[i]: 在第i+1天买入所能获得的最大利润
    int dp[prices.size()];
    dp[prices.size() - 1] = 0;
    int max_profit = 0;
    for (int i = prices.size() - 2; i >= 0; --i) {
        dp[i] = std::max(0, prices[i + 1] - prices[i] + dp[i + 1]);
        max_profit = std::max(dp[i], max_profit);
    }
    return max_profit;
}

int main() {
    std::cout << maxProfit({7,1,5,3,6,4}) << std::endl;
    std::cout << maxProfit({7,6,4,3,1}) << std::endl;
}