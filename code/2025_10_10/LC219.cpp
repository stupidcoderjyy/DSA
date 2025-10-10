
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;

//时间复杂度：O(n) 空间复杂度：O(n)
//2 6 1 2 3 1 2 3
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    std::unordered_map<int, int> num_to_index;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = num_to_index.find(nums[i]);
        if (it != num_to_index.end()) {
            if (i - it->second <= k) {
                return true;
            }
            it->second = i;
        } else {
            num_to_index[nums[i]] = i;
        }
    }
    return false;
}

int main() {
    while (true) {
        int k, n;
        std::cin >> k >> n;
        if (!n) {
            break;
        }
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }
        std::cout << containsNearbyDuplicate(nums, k) << std::endl;
    }
}