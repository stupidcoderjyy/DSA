//
// Created by JYY on 25-6-28.
//
#include <vector>
#include <iostream>
using namespace std;

#define test(x) cout << x << endl

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> vec;
    vec.resize(matrix.size() * matrix[0].size());
    int left = 0, top = 0, right = matrix[0].size() - 1, down = matrix.size() - 1;
    int p = 0;
    while (true) {
        if (top > down) {
            break;
        }
        for (int i = left; i <= right; ++i) {
            vec[p++] = matrix[top][i];
        }
        top++;
        if (left > right) {
            break;
        }
        for (int i = top; i <= down; ++i) {
            vec[p++] = matrix[i][right];
        }
        right--;
        if (top > down) {
            break;
        }
        for (int i = right; i >= left; --i) {
            vec[p++] = matrix[down][i];
        }
        down--;
        if (left > right) {
            break;
        }
        for (int i = down; i >= top; --i) {
            vec[p++] = matrix[i][left];
        }
        left++;
    }
    return vec;
}

//https://leetcode.cn/problems/spiral-matrix/description/
int main() {
    vector<vector<int>> m = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    spiralOrder(m);
}