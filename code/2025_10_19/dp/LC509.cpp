//
// Created by PC on 2025/10/21.
//

#include <algorithm>
#include <iostream>
#include <ostream>

//时间复杂度O(n) 空间复杂度O(n)
int fib(int n) {
    int dp[std::max(2, n + 1)];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    for (int i = 0; i < 10; ++i) {
        std::cout << fib(i) << '\n';
    }
}

