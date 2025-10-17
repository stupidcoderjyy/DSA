//
// Created by PC on 2025/10/17.
//

#include <exception>
#include <iostream>

class DivideByZeroException : public std::exception {
public:
    const char *what() const noexcept override {
        return "divide by 0";
    }
};

int divide(int a, int b) {
    if (b == 0) {
        throw DivideByZeroException();
    }
    return a / b;
}

int main() {
    try {
        std::cout << divide(2, 1) << std::endl;
        std::cout << divide(2, 0) << std::endl;
    } catch (DivideByZeroException& e) {
        std::cerr << e.what() << std::endl;
    }
}