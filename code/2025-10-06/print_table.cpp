//
// Created by PC on 2025/10/6.
//

#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> list;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        std::string s;
        std::cin >> s;
        list.push_back(s);
    }
    for (int i = 0; i < list.size(); ++i) {
        std::cout << std::right << std::setw(4) << (i + 1);
        std::cout << std::right << std::setw(10) << list[i];
        std::cout << std::right << std::setw(10) << list[i].length() << std::endl;
    }
}