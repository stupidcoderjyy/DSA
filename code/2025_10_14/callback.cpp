//
// Created by PC on 2025/10/16.
//

#include <iostream>

typedef int (*Func)(int);

void Process(int arr[], int len, Func f) {
    for (int i = 0; i < len; ++i) {
        arr[i] = f(arr[i]);
    }
}

int main() {
    Func f = [](int i) {
        return i * i;
    };
    int arr[] = {1, 2, 3, 4, 5};
    Process(arr, 5, f);
    for (int num : arr) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}