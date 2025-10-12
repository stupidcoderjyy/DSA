//
// Created by PC on 2025/10/12.
//

#include <iostream>

void Print(int i) {
    std::cout << i << std::endl;
}

void Print(double d) {
    std::cout << d << std::endl;
}

void Print(const char* s) {
    std::cout << s << std::endl;
}

int main() {
    Print(1);
    Print(2.0);
    Print("s");
}