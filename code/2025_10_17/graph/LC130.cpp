//
// Created by stupid_coder_jyy on 25-10-18.
//

#include <vector>
#include <cstring>
#include <iostream>

using std::vector;

void VisitArea(int i, int j, vector<vector<char>>& grid, int width, int height) {
    if (i < 0 || i >= height || j < 0 || j >= width) {
        return;
    }
    if (grid[i][j] == 'O') {
        grid[i][j] = '#';
        VisitArea(i - 1, j, grid, width, height);
        VisitArea(i + 1, j, grid, width, height);
        VisitArea(i, j + 1, grid, width, height);
        VisitArea(i, j - 1, grid, width, height);
    }
}

void solve(vector<vector<char>>& grid) {
    int height = grid.size(), width = grid[0].size();
    for (int i = 0; i < height; ++i) {
        if (grid[i][0] == 'O') {
            VisitArea(i, 0, grid, width, height);
        }
        if (grid[i][width - 1] == 'O') {
            VisitArea(i, width - 1, grid, width, height);
        }
    }
    for (int j = 0; j < width; ++j) {
        if (grid[0][j] == 'O') {
            VisitArea(0, j, grid, width, height);
        }
        if (grid[height - 1][j] == 'O') {
            VisitArea(height - 1, j, grid, width, height);
        }
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == 'O') {
                grid[i][j] = 'X';
            }
        }
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == '#') {
                grid[i][j] = 'O';
            }
        }
    }
}

int main() {
//    vector<vector<char>> grid{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    vector<vector<char>> grid{
        {'O','X','X','O','X'},
        {'X','O','O','X','O'},
        {'X','O','X','O','X'},
        {'O','X','O','O','O'},
        {'X','X','O','X','O'}
    };
    solve(grid);
}