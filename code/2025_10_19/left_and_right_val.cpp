//
// Created by PC on 2025/10/21.
//

#include <iostream>
#include <type_traits>

//如果不使用T&&，则无法保留传入的类型，永远输出左值
template<typename T>
void PrintType(T&&) {
    if (std::is_rvalue_reference_v<T&&>) {
        std::cout << "r_val" << std::endl;
    } else {
        std::cout << "l_val" << std::endl;;
    }
}

int main() {
    int a = 1;
    PrintType(1);               //r
    PrintType(a);           //l

    int&& b = std::move(a);
    PrintType(b);           //l
    PrintType(std::move(b));    //r
}