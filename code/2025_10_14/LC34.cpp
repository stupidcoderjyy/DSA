//
// Created by PC on 2025/10/16.
//

#include <iostream>
#include <vector>

using std::vector;

//时间复杂度O(logN) 空间复杂度O(1)
int IndexOfFirstLarger(const vector<int>& nums, int target) {
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

vector<int> searchRange(const vector<int>& nums, int target) {
    int begin = IndexOfFirstLarger(nums, target - 1);
    if (begin == nums.size() || nums[begin] != target) {
        return {-1, -1};
    }
    return {begin, IndexOfFirstLarger(nums, target) - 1};
}

int main() {
    while (true) {
        int target, n;
        std::cin >> target >> n;
        if (n < 0) {
            break;
        }
        vector<int> vec(n);
        for (int& num : vec) {
            std::cin >> num;
        }
        auto range = searchRange(vec, target);
        std::cout << range[0] << ' ' << range[1] << std::endl;
    }
    return 0;
}