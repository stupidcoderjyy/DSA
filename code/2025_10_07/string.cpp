//
// Created by PC on 2025/10/7.
//

#include <iostream>

int main() {
    const char* s = "abcdef";
    int i = 0;
    while (s[i] != '\0') {
        std::cout << s[i] << ' ' << static_cast<int>(s[i]) << '\n';
        i++;
    }
    std::cout << std::endl;
}