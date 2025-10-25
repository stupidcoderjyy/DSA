//
// Created by PC on 2025/10/25.
//

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> map{
            {"apple", 100},
            {"banana", 200},
            {"cherry", 300},
        };
    for (const auto&[s, i] : map) {
        std::cout << s << " -> " << i << "\n";
    }
}
