//
// Created by PC on 2025/10/6.
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using std::vector;
/*
 6 2 3 1 2 4 3 7
 3 1 4 4 4
 4 1 1 1 1 10
*/
int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, r = 0, sum = 0, min_len = INT_MAX;
    while (true) {
        while (r < nums.size() && sum < target) {
            sum += nums[r++];
        }
        if (sum < target && r == nums.size()) {
            break;
        }
        while (sum >= target) {
            sum -= nums[l++];
        }
        min_len = std::min(min_len, r - l + 1);
    }
    return min_len == INT_MAX ? 0 : min_len;
}

int main() {
    int len;
    std::cin >> len;
    vector<int> vec(len);
    for (int i = 0; i < len; ++i) {
        std::cin >> vec[i];
    }
    int target;
    std::cin >> target;
    std::cout << minSubArrayLen(target, vec) << std::endl;
}