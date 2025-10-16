#include <iostream>
#include <vector>
//
// Created by PC on 2025/10/16.
//
using std::vector;

//时间复杂度O(logN) 空间复杂度O(1)
int findMin(const vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    //搜索递减的位置
    while (l < r) {
        int m = l + ((r - l) >> 1);
        if (nums[0] > nums[m]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    //l==len-1时，数组有序或者最后一位递减
    return std::min(nums[0], nums[l]);
}

int main() {
    std::cout << findMin({3,4,5,1,2}) << '\n';
    std::cout << findMin({4,5,6,7,0,1,2}) << '\n';
    std::cout << findMin({1,2,3,4,5}) << '\n';
    std::cout << findMin({5,1,2,3,4}) << '\n';
    std::cout << findMin({4,5,1,2,3}) << '\n';
    std::cout << findMin({3,4,5,1,2}) << '\n';
    std::cout << findMin({2,3,4,5,1}) << '\n';
    std::cout << findMin({1}) << '\n';
}