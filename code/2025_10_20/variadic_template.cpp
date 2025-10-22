//
// Created by PC on 2025/10/21.
//

#include <iostream>

template<typename ... Tn>
int Sum(Tn ... nums) {
    int sum{};
    ((sum += nums), ...);
    return sum;
}

int main() {
    std::cout << Sum(1, 2, 3, 4) << std::endl;
}


