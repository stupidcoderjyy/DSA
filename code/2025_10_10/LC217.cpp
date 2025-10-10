
#include <iostream>
#include <unordered_set>
#include <vector>

using std::vector;

//时间复杂度：O(n) 空间复杂度：O(n)
bool containsDuplicate(const vector<int>& nums) {
    std::unordered_set<int> set;
    for (int num : nums) {
        if (set.count(num)) {
            return true;
        }
        set.insert(num);
    }
    return false;
}

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }
        std::cout << containsDuplicate(nums) << std::endl;
    }
}