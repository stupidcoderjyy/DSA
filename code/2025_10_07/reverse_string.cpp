//
// Created by PC on 2025/10/7.
//

#include <algorithm>
#include <iostream>

void reverse_string(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        std::swap(str[i], str[j]);
    }
}

int main() {
    while (true) {
        std::string str;
        std::getline(std::cin, str);
        reverse_string(const_cast<char*>(str.c_str()));
        std::cout << str << std::endl;
        if (str.empty()) {
            break;
        }
    }
}