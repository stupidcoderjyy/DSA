//
// Created by PC on 2025/10/6.
//

#include <iostream>

int main() {
    int score;
    std::cin >> score;
    if (score < 60) {
        std::cout << "E";
    } else if (score < 70) {
        std::cout << "D";
    } else if (score < 80) {
        std::cout << "C";
    } else if (score < 90) {
        std::cout << "B";
    } else {
        std::cout << "A";
    }
    std::cout << std::endl;
}
