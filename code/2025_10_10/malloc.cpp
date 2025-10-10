//
// Created by PC on 2025/10/10.
//

#include <iostream>

int main() {
    int len;
    std::cin >> len;
    auto arr = static_cast<int*>(malloc(len * sizeof(int)));
    for (int i = 0; i < len; ++i) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    free(arr);
}
