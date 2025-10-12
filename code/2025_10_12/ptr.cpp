//
// Created by PC on 2025/10/12.
//

#include <iostream>

void func(int* ptr) {
    if (ptr) {
        std::cout << *ptr << std::endl;
    } else {
        std::cout << "null" << std::endl;
    }
}

int main() {
    int* ptr = nullptr;
    int num = 10;
    func(ptr);
    func(&num);
}