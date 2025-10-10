//
// Created by PC on 2025/10/10.
//

#include <iostream>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    std::string type;
    std::cin >> type;
    Data d;
    if (type == "int") {
        std::cin >> d.i;
        std::cout << d.i << std::endl;
    } else if (type == "float") {
        std::cin >> d.f;
        std::cout << d.f << std::endl;
    } else if (type == "char") {
        std::cin >> d.c;
        std::cout << d.c << std::endl;
    } else {
        std::cerr << "invalid type: " << type << std::endl;
    }
}
