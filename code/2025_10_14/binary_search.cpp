//
// Created by PC on 2025/10/16.
//

#include <iostream>
#include <vector>

using std::vector;

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

int main() {
    std::cout << IndexOf({}, 1) << '\n';
    std::cout << IndexOf({1}, 1) << '\n';
    std::cout << IndexOf({2}, 1) << '\n';
    std::cout << IndexOf({1,2,3}, 2) << '\n';
}