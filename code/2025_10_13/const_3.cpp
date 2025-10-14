//
// Created by PC on 2025/10/14.
//

#include <iostream>

class A {
public:
    mutable int n = 10;
    int num = 2;

    void Print() const {
        std::cout << num << " " << ++n << std::endl;
    }
};

int main() {
    A a;
    a.Print();
    a.Print();
}
