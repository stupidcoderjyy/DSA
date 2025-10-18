//
// Created by stupid_coder_jyy on 25-10-18.
//

#include <iostream>

class Point {
public:
    int x;
    int y;
    Point(): x(), y() {}
    Point(int x, int y): x(x), y(y) {}
};

void Test1() {
    auto* p = new Point(1, 2);
    std::cout << p->x << ',' << p->y << std::endl;
    delete p;
}

void Test2() {
    try {
        auto* p_arr = new Point[5]{{1,2},{2,3},{3,4},{4,5},{5,6}};
        for (int i = 0; i < 5; ++i) {
            auto& p = p_arr[i];
            std::cout << p.x << ',' << p.y << '\n';
        }
        delete[] p_arr;
    } catch (std::bad_alloc& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    Test1();
    Test2();
}