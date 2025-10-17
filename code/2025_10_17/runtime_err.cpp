//
// Created by PC on 2025/10/17.
//

#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("divide by 0");
    }
    return a / b;
}

int main() {
    try {
        std::cout << divide(2, 1) << std::endl;
        std::cout << divide(2, 0) << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}