//
// Created by PC on 2025/10/5.
//
#include <vector>
#include <iostream>

std::vector<int> plusOne(std::vector<int>& digits) {
    int len = digits.size();
    for (int i = len - 1; i >= 0; --i) {
        digits[i] = (digits[i] + 1) % 10;
        if (digits[i] != 0) {
            return digits;
        }
    }
    std::vector<int> vec;
    vec.resize(len + 1);
    vec[0] = 1;
    return digits;
}

int main() {
    int len;
    std::cin >> len;
    std::vector<int> vec(len);
    for (int i = 0; i < len; i++) {
        std::cin >> vec[i];
    }
    vec = plusOne(vec);
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}