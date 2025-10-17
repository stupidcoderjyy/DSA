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

int calc1(int a, int b) {
    return divide(a, b);
}

int calc2(int a, int b) {
    return calc1(a, b);
}

int main() {
    try {
        std::cout << calc2(2, 1) << std::endl;
        std::cout << calc2(2, 0) << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}