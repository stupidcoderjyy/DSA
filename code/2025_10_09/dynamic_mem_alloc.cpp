//
// Created by PC on 2025/10/9.
//

#include <iostream>

int main() {
    auto arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
}
