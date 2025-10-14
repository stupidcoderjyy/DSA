//
// Created by PC on 2025/10/14.
//

#include <iostream>

enum class Color {
    RED, GREEN, BLUE
};

std::string ColorToString(Color c) {
    switch (c) {
        case Color::RED:
            return "RED";
        case Color::GREEN:
            return "GREEN";
        case Color::BLUE:
            return "BLUE";
    }
    return "";
}

int main() {
    // GREEN具有Color类作用域
    // Color c = GREEN;   error: 'GREEN' was not declared in this scope
    std::cout << static_cast<int>(Color::GREEN) << std::endl;

    for (const auto& c : {Color::RED, Color::BLUE, Color::GREEN}) {
        std::cout << ColorToString(c) << '\n';
    }
    return 0;
}