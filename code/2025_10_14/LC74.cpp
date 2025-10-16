//
// Created by PC on 2025/10/16.
//

#include <iostream>
#include <vector>

using std::vector;

//时间复杂度O(logN) 空间复杂度O(1)
int RowOf(const vector<vector<int>>& matrix, int target) {
    int l = 0, r = matrix.size() - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (target < matrix[m].front()) {
            r = m - 1;
        } else if (target > matrix[m].back()) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return -1;
}

int IndexOf(const vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (target < nums[m]) {
            r = m - 1;
        } else if (target > nums[m]) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return -1;
}

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    int row = RowOf(matrix, target);
    if (row == -1) {
        return false;
    }
    return IndexOf(matrix[row], target) >= 0;
}

int main() {
    std::cout << searchMatrix({{1,3,5,7}, {10,11,16,20},{23,30,34,60}}, 3) << '\n';
    std::cout << searchMatrix({{1,3,5,7}, {10,11,16,20},{23,30,34,60}}, 13) << '\n';
    std::cout << searchMatrix({{1,3,5,7}, {10,11,16,20},{23,30,34,60}}, 0) << '\n';
    std::cout << searchMatrix({{1,3,5,7}, {10,11,16,20},{23,30,34,60}}, 61) << '\n';
}