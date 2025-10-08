//
// Created by PC on 2025/10/6.
//

#include <iomanip>
#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> generateMatrix(int n) {
    int left = 0, top = 0, right = n - 1, bottom = n - 1;
    int num = 1;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; ++i) {
        vector<int> vec;
        vec.resize(n);
        matrix.push_back(vec);
    }
    while (true) {
        for (int c = left; c <= right; c++) {
            matrix[top][c] = num++;
        }
        if (top++ == bottom) {
            break;
        }
        for (int r = top; r <= bottom; r++) {
            matrix[r][right] = num++;
        }
        if (right-- == left) {
            break;
        }
        for (int c = right; c >= left; c--) {
            matrix[bottom][c] = num++;
        }
        if (bottom-- == top) {
            break;
        }
        for (int r = bottom; r >= top; r--) {
            matrix[r][left] = num++;
        }
        if (left++ == right) {
            break;
        }
    }
    return matrix;
}

int main() {
    int n;
    std::cin >> n;
    auto result = generateMatrix(n);
    for (auto& list : result) {
        for (int i : list) {
            std::cout << std::left << std::setw(3) << i;
        }
        std::cout << std::endl;
    }
}