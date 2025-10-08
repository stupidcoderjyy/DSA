//
// Created by PC on 2025/10/8.
//

#include <iostream>

int main() {
    int arr[] = {1,2,3,4,5};
    int *p = arr;
    for (int i = 0; i < 5; ++i) {
        std::cout << *p++ << " ";
    }
    std::cout << std::endl;
}
