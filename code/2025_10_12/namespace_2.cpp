//
// Created by PC on 2025/10/12.
//

#include <iostream>
#include <cmath>

namespace geometry::shapes {
    double CalculateArea(int r) {
        return M_PI * r * r;
    }

    double CalculatePerimeter(int r) {
        return 2 * M_PI * r;
    }
}

using namespace geometry::shapes;

int main() {
    std::cout << CalculateArea(1) << " " << CalculatePerimeter(1) << std::endl;
}