//
// Created by PC on 2025/10/19.
//
#include <string>
#include <unordered_set>
#include <vector>

using std::vector;
using std::string;

vector<string> group;
vector<vector<string>> result;
std::unordered_set<int> occupied_columns;
std::unordered_set<int> occupied_diagonal_45;
std::unordered_set<int> occupied_diagonal_135;

//时间复杂度O(N!) 空间复杂度O(N)
bool IsPlaceValid(int r, int c) {
    return occupied_columns.find(c) == occupied_columns.end()
        && occupied_diagonal_45.find(r + c) == occupied_diagonal_45.end()
        && occupied_diagonal_135.find(r - c) == occupied_diagonal_135.end();
}

void Solve(int n, int r) {
    if (r == n) {
        result.push_back(group);
        return;
    }
    for (int c = 0; c < n; ++c) {
        if (IsPlaceValid(r, c)) {
            group[r][c] = 'Q';
            occupied_columns.insert(c);
            occupied_diagonal_45.insert(r + c);
            occupied_diagonal_135.insert(r - c);
            Solve(n, r + 1);
            group[r][c] = '.';
            occupied_columns.erase(c);
            occupied_diagonal_45.erase(r + c);
            occupied_diagonal_135.erase(r - c);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    result = {};
    occupied_columns = {};
    occupied_diagonal_45 = {};
    occupied_diagonal_135 = {};
    group = vector(n, string(n, '.'));
    Solve(n, 0);
    return result;
}

int main() {
    solveNQueens(1);
    solveNQueens(2);
    solveNQueens(3);
    solveNQueens(4);
}