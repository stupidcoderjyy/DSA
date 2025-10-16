//
// Created by PC on 2025/10/14.
//

#include <iostream>

enum class Color {
    Red, Green, Blue
};

std::string ColorToString(Color c) {
    switch (c) {
        case Color::Red:
            return "RED";
        case Color::Green:
            return "GREEN";
        case Color::Blue:
            return "BLUE";
        default:
            return "";
    }
}

int main() {
    // GREEN具有Color类作用域
    // Color c = GREEN;   error: 'GREEN' was not declared in this scope
    std::cout << static_cast<int>(Color::Green) << std::endl;

    for (const auto& c : {Color::Red, Color::Blue, Color::Green}) {
        std::cout << ColorToString(c) << '\n';
    }
    return 0;
}