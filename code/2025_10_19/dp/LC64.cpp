//
// Created by PC on 2025/10/21.
//

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using std::vector;

//时间复杂度O(MN) 空间复杂度O(MN)
int Solve1(const vector<vector<int>>& grid) {
    //dp[i][j]: 从(0,0)到(i,j)所需要的最小路径
    int h = grid.size(), w = grid[0].size();
    int dp[h][w];
    dp[0][0] = grid[0][0];
    for (int r = 1; r < h; ++r) {
        dp[r][0] = dp[r - 1][0] + grid[r][0];
    }
    for (int c = 1; c < w; ++c) {
        dp[0][c] = dp[0][c - 1] + grid[0][c];
    }
    for (int r = 1; r < h; ++r) {
        for (int c = 1; c < w; ++c) {
            dp[r][c] = grid[r][c] + std::min(dp[r - 1][c], dp[r][c - 1]);
        }
    }
    return dp[h - 1][w - 1];
}

//时间复杂度O(MN) 空间复杂度O(N)
int Solve2(const vector<vector<int>>& grid) {
    //dp[i]: 走到第i列所需要的最小路径
    int h = grid.size(), w = grid[0].size();
    int dp[w];
    memset(dp, 0, w * sizeof(int));
    for (int r = 0; r < h; ++r) {
        dp[0] += grid[r][0];
        for (int c = 1; c < w; ++c) {
            dp[c] = grid[r][c] + (r == 0 ? dp[c - 1] : std::min(dp[c], dp[c - 1]));
        }
    }
    return dp[w - 1];
}

int minPathSum(const vector<vector<int>>& grid) {
    return Solve2(grid);
}

int main() {
    std::cout << minPathSum({{1,3,1},{1,5,1},{4,2,1}}) << std::endl;
    std::cout << minPathSum({{1,2,3},{4,5,6}}) << std::endl;
    std::cout << minPathSum({{2}}) << std::endl;
}