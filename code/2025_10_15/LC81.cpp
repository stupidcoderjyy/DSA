//
// Created by PC on 2025/10/16.
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using std::vector;

//最好|最差|平均时间复杂度O(logN)|O(N)|O(logN)
int IndexOf(const vector<int>& nums, int target) {
    if (target == nums[0]) {
        return 0;
    }
    int l = 0, r = nums.size() - 1;
    //移除首位重复部分
    while (l < nums.size() && nums[l] == nums[0]) {
        l++;
    }
    while (r >= 0 && nums[r] == nums[0]) {
        r--;
    }
    //同LC33
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (nums[m] == target) {
            return m;
        }
        bool a = target < nums[l], b = nums[m] < nums[l], c = target >= nums[m];
        if (a & (!b | c) | !a & !b & c) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

bool search(const vector<int>& nums, int target) {
    return IndexOf(nums, target) >= 0;
}

void test(const vector<int>& vec, int begin, int end) {
    while (begin <= end) {
        int i = IndexOf(vec, begin);
        std::cout << std::setw(2);
        auto ans = std::find(vec.begin(), vec.end(), begin);
        if ((i < 0 && ans == vec.end()) || vec[i] == begin) {
            std::cout << '+';
        } else {
            std::cout << 'x';
        }
        begin++;
    }
    std::cout << std::endl;
}

int main() {
    //std::endl 调试需要
    test({1,2,3,4,6},0,7);
    test({6,1,2,3,4},0,7);
    test({2,3,4,6,1},0,7);
    test({6,6,1,1,2,3,4,4,5,5},0,7);
    test({1,0,1,1,1},-1,2);
    test({1,1,1,1,1},-1,2);
    test({1},0,2);
}

