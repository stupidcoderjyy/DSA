//
// Created by PC on 2025/10/16.
//

#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*pAdd)(int, int) = add;
    std::cout << pAdd(1, 2) << std::endl;
}