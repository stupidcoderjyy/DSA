//
// Created by PC on 2025/10/7.
//

#include <iostream>

void sort(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#define LEN 10

void print_arr(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[LEN];
    srand(time(nullptr));
    for (int& i : arr) {
        i = rand() % 10;
    }
    print_arr(arr, LEN);
    sort(arr, LEN);
    print_arr(arr, LEN);
}