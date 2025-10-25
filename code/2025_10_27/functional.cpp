//
// Created by PC on 2025/10/25.
//

#include <functional>
#include <iostream>

int Add(int a, int b) {
    return a + b;
}

int main() {
    std::function adder = [](int a, int b) {
        return a + b;
    };
    std::cout << adder(1, 2) << '\n';

    adder = &Add;
    std::cout << adder(2, 3) << '\n';

    using namespace std::placeholders;
    adder = std::bind(&Add, _1, _2);
    std::cout << adder(3, 4) << '\n';
}
