//
// Created by PC on 2025/10/6.
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using std::vector;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        //把nums[i]换到它应该去的地方 (nums[nums[i]-1])
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            std::swap(nums[nums[i] - 1], nums[i]);
        }
    }
    //找到第一个不符合规则的
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {
    int len;
    std::cin >> len;
    vector<int> vec(len);
    for (int i = 0; i < len; ++i) {
        std::cin >> vec[i];
    }
    std::cout << firstMissingPositive(vec) << std::endl;
}