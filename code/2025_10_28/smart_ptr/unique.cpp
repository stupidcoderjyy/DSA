//
// Created by PC on 2025/10/30.
//

#include <iostream>
#include <memory>

int* GetArray() {
    auto arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = i;
    }
    return arr;
}

int main() {
    std::unique_ptr<int[]> p1(GetArray());
    std::cout << p1[3] << '\n';
    std::unique_ptr p2(std::move(p1));
    std::cout << p2[3] << '\n';
    return 0;
}