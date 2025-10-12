//
// Created by PC on 2025/10/12.
//

#include <iostream>

void Print(int i) {
    std::cout << i << std::endl;
}

void Print(float f) {
    std::cout << f << std::endl;
}

int main() {
    // Print(1.0); call of overloaded 'Print(double)' is ambiguous
    Print(1.0f);
    Print(1);
}