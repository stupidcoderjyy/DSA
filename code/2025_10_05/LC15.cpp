#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r] + nums[i];
            if (sum > 0) {
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                result.push_back({nums[i], nums[l++], nums[r--]});
                while (l < r && nums[l] == nums[l - 1]) {
                    l++;
                }
                while (l < r && nums[r] == nums[r + 1]) {
                    r--;
                }
            }
        }
    }
    return result;
}

int main() {
    int len;
    std::cin >> len;
    std::vector<int> vec(len);
    for (int i = 0; i < len; i++) {
        std::cin >> vec[i];
    }
    auto result = threeSum(vec);
    for (auto &v : result) {
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}