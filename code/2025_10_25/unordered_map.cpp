//
// Created by PC on 2025/10/25.
//

#include <iostream>
#include <string>
#include <unordered_map>

void Func(std::unordered_map<std::string, int>& map, const std::string& key) {
    if (map.find(key) == map.end()) {
        map[key] = 10;
    } else {
        map[key] += 10;
    }
}

int main() {
    std::unordered_map<std::string, int> map{
        {"a", 1},
        {"b", 2},
        {"c", 3},
    };
    Func(map, "a");
    Func(map, "a");
    Func(map, "d");
    for (const auto&[s, i] : map) {
        std::cout << s << " -> " << i << "\n";
    }
}