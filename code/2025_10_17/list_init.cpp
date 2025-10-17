//
// Created by PC on 2025/10/17.
//

#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

struct Box {
    Box(int w, int h) {
        std::cout << "Box(int, int) ";
        std::cout << w << ' ' << h << std::endl;
    }

    Box(std::initializer_list<int> sizes) {
        std::cout << "Box(std::initializer_list<int>) ";
        for (const int& s : sizes) {
            std::cout << s << ' ';
        }
        std::cout << std::endl;
    }
};

int main() {
    Point p{1, 2};
    std::cout << p.x << "," << p.y << std::endl;

    std::vector vec{1, 2, 3, 4};
    for (const int& num : vec) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    Box b1{1};
    Box b2{1,2};
    Box b3(1,2);
    Box b4{1,2,3,4};
}