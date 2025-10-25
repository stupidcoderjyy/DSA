//
// Created by PC on 2025/10/25.
//

#include <iostream>
#include <set>

int main() {
    std::set set{1, 5, 3, 9, 7};
    for (const auto& num : set) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}
