//
// Created by PC on 2025/10/22.
//

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
using std::vector;

//时间复杂度O(N) 空间复杂度O(N)
int minimumTotal(const vector<vector<int>>& triangle) {
    //dp[i] 走到某行第i位的最小路径和
    std::vector<int> dp(triangle.size());
    dp[0] = triangle[0][0];
    for (int lv = 1; lv < triangle.size(); ++lv) {
        dp[lv] = dp[lv - 1] + triangle[lv][lv];
        for (int i = lv - 1; i >= 1; --i) {
            dp[i] = triangle[lv][i] + std::min(dp[i], dp[i - 1]);
        }
        dp[0] += triangle[lv][0];
    }
    int min = INT_MAX;
    for (int num : dp) {
        min = std::min(min, num);
    }
    return min;
}

int main() {
    std::cout << minimumTotal({{2}, {3,4}}) << std::endl;
    std::cout << minimumTotal({{2}, {3,4}, {6,5,7}}) << std::endl;
    std::cout << minimumTotal({{2}, {3,4}, {6,5,7}, {4,1,8,3}}) << std::endl;
}