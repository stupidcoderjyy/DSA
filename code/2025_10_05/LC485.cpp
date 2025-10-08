#include <algorithm>
#include <vector>
#include <iostream>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int len = 0, max_len = 0;
    for (int num : nums) {
        if (num == 1) {
            len++;
        } else {
            max_len = std::max(len, max_len);
            len = 0;
        }
    }
    return std::max(len, max_len);
}

int main() {
    int len;
    std::cin >> len;
    std::vector<int> vec(len);
    for (int i = 0; i < len; i++) {
        std::cin >> vec[i];
    }
    std::cout << findMaxConsecutiveOnes(vec) << std::endl;
    return 0;
}