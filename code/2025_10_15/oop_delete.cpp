
#include <iostream>

class Shape {
public:
    virtual ~Shape() {
        std::cout << "~Shape" << '\n';
    }
};

class Rect : public Shape {
public:
    ~Rect() override {
        std::cout << "~Rect" << '\n';
    }
};

class Circle : public Shape {
public:
    ~Circle() override {
        std::cout << "~Circle" << '\n';
    }
};

int main() {
    Shape* shapes[] = {new Rect, new Circle, new Shape};
    for (auto s : shapes) {
        delete s;
    }
}