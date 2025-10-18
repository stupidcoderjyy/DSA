//
// Created by stupid_coder_jyy on 25-10-18.
//

#include <vector>
#include <iostream>

using std::vector;

//时间复杂度O(MN) 最坏空间复杂度O(MN)
void VisitIsland(int i, int j, vector<vector<char>>& grid, int width, int height) {
    if (i < 0 || i >= height || j < 0 || j >= width) {
        return;
    }
    if (grid[i][j] == '1') {
        grid[i][j] = 0;
        VisitIsland(i - 1, j, grid, width, height);
        VisitIsland(i + 1, j, grid, width, height);
        VisitIsland(i, j + 1, grid, width, height);
        VisitIsland(i, j - 1, grid, width, height);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int height = grid.size(), width = grid[0].size();
    int count = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == '1') {
                VisitIsland(i, j, grid, width, height);
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> vec{{'1','0'},{'0','1'}};
    std::cout << numIslands(vec) << std::endl;
}