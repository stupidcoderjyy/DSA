//
// Created by PC on 2025/10/21.
//

#include <algorithm>
#include <iostream>

template<typename T>
bool Max(const T& a, const T& b) {
    return std::max(a, b);
}

template<typename T = int>
class Box {
public:
    Box(T width, T height): width_(width), height_(height) {}
    T GetVolume() const {
        return width_ * height_;
    }
private:
    T width_;
    T height_;
};

int main() {
    std::cout << Max(1, 2) << std::endl;
    std::cout << Max(1u, 2u) << std::endl;
    std::cout << Max(1.0f, 2.0f) << std::endl;
    std::cout << Max(1.0, 2.0) << std::endl;

    std::cout << Box(1, 2).GetVolume() << std::endl;
    std::cout << Box(1.5, 2.6).GetVolume() << std::endl;
    std::cout << Box(1u, 2u).GetVolume() << std::endl;
    std::cout << Box(2.5f, 4.0f).GetVolume() << std::endl;
}
