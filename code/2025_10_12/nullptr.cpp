//
// Created by PC on 2025/10/12.
//

#include <iostream>
#include <cmath>

void Func1(int* p) {
    std::cout << p << std::endl;
}

void Func2(int i) {
    std::cout << i << std::endl;
}

int main() {
    Func1(nullptr);
    Func1(NULL);
    Func1(0);
    // Func2(nullptr);  error: cannot convert 'std::nullptr_t' to 'int'
    Func2(NULL);    //warning: passing NULL to non-pointer argument 1 of 'void Func2(int)'
    Func2(0);
}