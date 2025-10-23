//
// Created by PC on 2025/10/23.
//

#include <array>
#include <iostream>

void Double(std::array<int, 5>& arr) {
    for (int& num : arr) {
        num *= 2;
    }
}

int main() {
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    Double(arr);
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
