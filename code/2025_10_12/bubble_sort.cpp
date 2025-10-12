//
// Created by PC on 2025/10/12.
//

#include <iostream>
#include <vector>

using std::vector;

//排序算法的稳定性：相等元素排序后是否保持相对顺序不变
//最好复杂度：O(n) 最差复杂度：O(n^2)
void BubbleSort(vector<int>& nums) {
    bool sorted = false;
    for (int i = 0; !sorted && i < nums.size(); ++i) {
        sorted = true;
        for (int j = 1; j < nums.size() - i; ++j) {
            if (nums[j - 1] > nums[j]) {
                std::swap(nums[j - 1], nums[j]);
                sorted = false;
            }
        }
    }
}

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n < 0) {
            break;
        }
        vector<int> vec(n);
        for (int& num : vec) {
            std::cin >> num;
        }
        BubbleSort(vec);
        for (const int& num : vec) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}