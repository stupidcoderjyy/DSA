//
// Created by PC on 2025/10/16.
//

#include <iostream>
#include <vector>
using std::vector;

int IndexOfFirstLess(const vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (nums[m] >= target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int searchInsert(const vector<int>& nums, int target) {
    return IndexOfFirstLess(nums, target) + 1;
}

int main() {
    std::cout << searchInsert({1,3,5,6}, 5) << '\n';
    std::cout << searchInsert({1,3,5,6}, 2) << '\n';
    std::cout << searchInsert({1,3,5,6}, 7) << '\n';
    std::cout << searchInsert({1,3,5,6}, 0) << '\n';
}