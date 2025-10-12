//
// Created by PC on 2025/10/12.
//

#include <iostream>

namespace math {

    int Add(int a, int b) {
        return a + b;
    }

    int Subtract(int a, int b) {
        return a - b;
    }

}

using math::Add;
using math::Subtract;

int main() {
    std::cout << Add(1, 2) << '\n';
    std::cout << Subtract(1, 2) << std::endl;
}