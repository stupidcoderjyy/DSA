//
// Created by PC on 2025/10/16.
//

#include <iostream>
int global = 0;

int Func() {
    static int local_static = 0;
    return local_static++;
}

int main() {
    for (int i = 0; i < 5; ++i) {
        std::cout << global++ << ' ' << Func() << '\n';
    }
    std::cout << std::endl;
}