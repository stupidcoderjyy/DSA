//
// Created by PC on 2025/10/8.
//
#include <algorithm>
#include <iostream>

void get_max_val(int arr[], int len, int& max) {
    int result = INT_MIN;
    for (int i = 0; i < len; ++i) {
        result = std::max(result, arr[i]);
    }
    max = result;
}

int main() {
    int arr[] = {1,2,3,4,5};
    int max;
    get_max_val(arr, 5, max);
    std::cout << max << std::endl;
}