//
// Created by PC on 2025/10/11.
//

#include <cstring>
#include <iostream>

int main() {
    int src[10];
    memset(src, 0, sizeof(src));
    for (int num : src) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
