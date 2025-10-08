//
// Created by PC on 2025/10/7.
//

#include <iostream>

int find(int arr[], int len, int val) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

void print_arr(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#define LEN 10

int main() {
    int arr[LEN];
    srand(time(nullptr));
    for (int& i : arr) {
        i = rand() % 10;
    }
    print_arr(arr, LEN);
    while (true) {
        int num;
        std::cin >> num;
        if (num < 0) {
            break;
        }
        std::cout << find(arr, LEN, num) << std::endl;
    }
}