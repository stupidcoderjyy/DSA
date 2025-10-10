//
// Created by PC on 2025/10/9.
//

#include <iostream>

void alloc_on_stack() {
    int arr[] = {1,2,3,4,5};
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void alloc_on_heap() {
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
    alloc_on_heap();
    alloc_on_stack();
}
