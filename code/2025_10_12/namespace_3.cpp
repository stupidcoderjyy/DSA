//
// Created by PC on 2025/10/12.
//

#include <iostream>
#include <cmath>

namespace {
    int counter = 0;

    void IncrementCounter() {
        counter++;
    }
}

int main() {
    for (int i = 0; i < 10; ++i) {
        IncrementCounter();
        std::cout << counter << '\n';
    }
}