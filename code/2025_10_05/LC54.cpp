//
// Created by PC on 2025/10/5.
//
#include <vector>
#include <iostream>

using std::vector;
using std::cin;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int left = 0, top = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
    vector<int> vec;
    vec.reserve((right + 1) * (bottom + 1));
    while (true) {
        for (int c = left; c <= right; c++) {
            vec.push_back(matrix[top][c]);
        }
        if (top++ == bottom) {
            break;
        }
        for (int r = top; r <= bottom; r++) {
            vec.push_back(matrix[r][right]);
        }
        if (right-- == left) {
            break;
        }
        for (int c = right; c >= left; c--) {
            vec.push_back(matrix[bottom][c]);
        }
        if (bottom-- == top) {
            break;
        }
        for (int r = bottom; r >= top; r--) {
            vec.push_back(matrix[r][left]);
        }
        if (left++ == right) {
            break;
        }
    }
    return vec;
}
//3 3 1 2 3 4 5 6 7 8 9
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; ++i) {
        vector<int> vec;
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            vec.push_back(val);
        }
        matrix.push_back(vec);
    }
    auto res = spiralOrder(matrix);
    for (int val : res) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}