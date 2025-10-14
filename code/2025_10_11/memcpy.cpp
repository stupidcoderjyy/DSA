//
// Created by PC on 2025/10/11.
//

#include <cstring>
#include <iostream>

int main() {
    int src[] = {1, 2, 3, 4, 5};
    int dest[5];
    memcpy(dest, src, sizeof(src));
    for (const int& num : dest) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
