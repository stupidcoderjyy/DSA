//
// Created by PC on 2025/10/10.
//

#include <iostream>

enum Date {
    Mon, Tue, Wed, Thu, Fri, Sat, Sun
};

std::string map[] = {
    "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"
};

//enum感觉没用
int main() {
    int date;
    std::cin >> date;
    if (date >= 1 && date <= 7) {
        std::cout << map[static_cast<Date>(date - 1)] << std::endl;
    } else {
        std::cerr << "invalid date: " << date << std::endl;
    }
}
