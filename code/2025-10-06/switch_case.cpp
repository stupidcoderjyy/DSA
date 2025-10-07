//
// Created by PC on 2025/10/6.
//

#include <iostream>

int main() {
    int date;
    std::cin >> date;
    switch (date) {
        case 1:
            std::cout << "Monday";
            break;
        case 2:
            std::cout << "Tuesday";
            break;
        case 3:
            std::cout << "Wednesday";
            break;
        case 4:
            std::cout << "Thursday";
            break;
        case 5:
            std::cout << "Friday";
            break;
        case 6:
            std::cout << "Saturday";
            break;
        case 7:
            std::cout << "Sunday";
            break;
        default:
            std::cerr << "Invalid date" << std::endl;
            return 1;
    }
    std::cout << std::endl;
}
