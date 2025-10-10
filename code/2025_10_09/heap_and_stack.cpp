//
// Created by PC on 2025/10/9.
//

#include <iostream>

void AllocOnStack() {
    int arr[] = {1, 2, 3, 4, 5};
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void AllocOnHeap() {
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

int main() {
    AllocOnHeap();
    AllocOnStack();
}
