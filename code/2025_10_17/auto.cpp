//
// Created by PC on 2025/10/17.
//

#include <algorithm>
#include <iostream>

template<typename T, typename U>
auto FindMax(T t, U u) -> decltype(std::max(t, u)) {
    return std::max(t, u);
}

int main() {
    std::cout << FindMax(1, 2) << std::endl;
    std::cout << FindMax(1.0f, 3.0f) << std::endl;
    std::cout << FindMax(1LL, 4LL) << std::endl;
}
