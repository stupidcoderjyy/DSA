//
// Created by PC on 2025/10/10.
//

#include <iostream>

int main() {
    auto arr = static_cast<int*>(malloc(5 * sizeof(int)));
    srand(time(nullptr));
    for (int i = 0; i < 5; ++i) {
        arr[i] = rand() % 10;
    }
    if (auto* new_arr = static_cast<int*>(realloc(arr, 10 * sizeof(int)))) {
        arr = new_arr;
    } else {
        free(arr);
        return 1;
    }
    for (int i = 5; i < 10; ++i) {
        arr[i] = rand() % 10;
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    free(arr);
}
