//
// Created by JYY on 25-6-26.
//

#include <vector>
#include <iostream>

using namespace std;

int searchLeft(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] > target || nums[m] == target && m > 0 && nums[m - 1] == target) {
            r = m - 1;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return -1;
}

int searchRight(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] > target) {
            r = m - 1;
        } else if (nums[m] < target || nums[m] == target && m < nums.size() - 1 && nums[m + 1] == target) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return -1;
}


//https://leetcode.cn/problems/search-insert-position/description/
vector<int> searchRange(vector<int> &nums, int target) {
    return {searchLeft(nums, target), searchRight(nums, target)};
}

#define test(vec, x) cout << searchLeft(vec, x) << searchRight(vec, x) <<  endl

int main() {
    vector<int> vec{5, 7, 7, 8, 8, 10};
    test(vec, 8);
    test(vec, 6);
    vec = {};
    test(vec, 1);
}