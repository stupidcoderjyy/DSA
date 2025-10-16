//
// Created by PC on 2025/10/16.
//

#include <iostream>
#include <vector>

using std::vector;

//时间复杂度O(logN) 空间复杂度O(1)
int search(const vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (nums[m] == target) {
            return m;
        }
        //列右侧区间的逻辑表达式
        //Y=A(BC+B') + A'B'C
        bool a = target < nums[l], b = nums[m] < nums[l], c = target >= nums[m];
        if (a & (!b | c) | !a & !b & c) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    //std::endl 调试需要
    for (int i = 1; i <= 5; ++i) {
        std::cout << search({1,2,3,4,5}, i) << std::endl;
    }
    for (int i = 1; i <= 5; ++i) {
        std::cout << search({5,1,2,3,4}, i) << std::endl;
    }
    std::cout.flush();
    for (int i = 1; i <= 5; ++i) {
        std::cout << search({2,3,4,5,1}, i) << std::endl;
    }
}

