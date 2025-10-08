//
// Created by PC on 2025/10/7.
//

#include <iostream>

int factorial(int n) {
    if (n < 0) {
        return -1;
    }
    if (n <= 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

int main() {
    for (int i = -1; i < 10; ++i) {
        std::cout << factorial(i) << '\n';
    }
    std::cout.flush();
}