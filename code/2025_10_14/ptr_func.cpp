//
// Created by PC on 2025/10/16.
//

#include <iostream>

int* FindMax(int arr[], int len) {
    int max = INT_MIN;
    int *p = arr, *p_max = nullptr;
    for (int i = 0; i < len; ++i) {
        if (*p > max) {
            max = *p;
            p_max = p;
        }
        ++p;
    }
    return p_max;
}

int main() {
    int arr[] = {1, 2, 5, 4, 3, 15};
    std::cout << *FindMax(arr, 6) << std::endl;
}