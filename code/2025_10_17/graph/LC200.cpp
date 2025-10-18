//
// Created by stupid_coder_jyy on 25-10-18.
//

#include <vector>
#include <cstring>
#include <iostream>

using std::vector;

void VisitIsland(int i, int j, const vector<vector<char>>& grid, vector<vector<bool>>& visited, int width, int height) {
    if (i < 0 || i >= height || j < 0 || j >= width) {
        return;
    }
    if (!visited[i][j] && grid[i][j] == '1') {
        visited[i][j] = true;
        VisitIsland(i - 1, j, grid, visited, width, height);
        VisitIsland(i + 1, j, grid, visited, width, height);
        VisitIsland(i, j + 1, grid, visited, width, height);
        VisitIsland(i, j - 1, grid, visited, width, height);
    }
}

int numIslands(const vector<vector<char>>& grid) {
    int height = grid.size(), width = grid[0].size();
    vector<vector<bool>> visited(height);
    for (auto& vec : visited) {
        vec.resize(width, false);
    }
    int count = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (visited[i][j] || grid[i][j] == '0') {
                continue;
            }
            VisitIsland(i, j, grid, visited, width, height);
            count++;
        }
    }
    return count;
}

int main() {
    std::cout << numIslands({{'1','0'},{'0','1'}}) << std::endl;
}