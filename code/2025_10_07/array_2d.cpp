//
// Created by PC on 2025/10/7.
//

#include <iostream>

#define ROWS 1
#define COLUMNS 1

int sum(int arr[][COLUMNS]) {
    int sum = 0;
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLUMNS; ++c) {
            sum += arr[r][c];
        }
    }
    return sum;
}

int main() {
    int arr[ROWS][COLUMNS];
    srand(time(nullptr));
    for (auto & r : arr) {
        for (int & c : r) {
            c = rand() % 10;
        }
    }
    std::cout << sum(arr) << std::endl;
}