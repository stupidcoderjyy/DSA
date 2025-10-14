//
// Created by PC on 2025/10/11.
//

#include <iostream>
#include <unordered_map>

using std::string;

std::unordered_map<char, int> map {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};

//时间复杂度O(n) 空间复杂度O(1)
int romanToInt(string s) {
    int num = 0;
    int i;
    for (i = 0; i < s.length() - 1; ++i) {
        if (map[s[i]] < map[s[i + 1]]) {
            num -= map[s[i]];
        } else {
            num += map[s[i]];
        }
    }
    if (i < s.length()) {
        num += map[s[i]];
    }
    return num;
}

int main() {
    std::cout << romanToInt("IX") << std::endl;
    std::cout << romanToInt("IV") << std::endl;
    std::cout << romanToInt("III") << std::endl;
    std::cout << romanToInt("I") << std::endl;
    std::cout << romanToInt("MCMXCIV") << std::endl;
    std::cout << romanToInt("LVIII") << std::endl;
    return 0;
}