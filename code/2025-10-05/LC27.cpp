#include <vector>
#include <iostream>

int removeElement(std::vector<int>& nums, int val) {
    int check = 0, set = 0;
    while (check < nums.size()) {
        if (nums[check] != val) {
            nums[set++] = nums[check++];
        } else {
            check++;
        }
    }
    return set;
}

int main() {
    int len;
    std::cin >> len;
    std::vector<int> vec(len);
    for (int i = 0; i < len; i++) {
        std::cin >> vec[i];
    }
    int val;
    std::cin >> val;
    std::cout << removeElement(vec, val) << std::endl;
    return 0;
}