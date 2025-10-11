//
// Created by PC on 2025/10/11.
//

#include <iostream>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() = 0;
};

class Rect : public Shape {
public:
    void draw() override {
        std::cout << "Rect" << '\n';
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Circle" << '\n';
    }
};

int main() {
    srand(time(nullptr));
    Shape* shapes[10];
    for (auto& shape : shapes) {
        if (rand() % 2 == 1) {
            shape = new Rect;
        } else {
            shape = new Circle;
        }
    }
    for (auto& shape : shapes) {
        shape->draw();
        delete shape;
    }
}