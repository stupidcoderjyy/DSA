//
// Created by PC on 2025/10/16.
//

#include <iomanip>
#include <iostream>
#include <vector>
using std::vector;

int IndexOfFirstGreater(const vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (nums[m] <= target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

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

int main() {
    vector vec = {1,2,3,4,5};
    for (int i = 0; i <= 6; ++i) {
        std::cout << std::setw(2) << IndexOfFirstLess(vec, i);
        std::cout << std::setw(2) << IndexOfFirstGreater(vec, i) << '\n';
    }
    std::cout << std::endl;
}