//
// Created by PC on 2025/10/16.
//

#include <iostream>
#include <ostream>

class Complex {
public:
    Complex(): rez(), imz() {}
    Complex(double rez, double imz): rez(rez), imz(imz) {}

    Complex operator+(const Complex& c) const {
        return {c.rez + rez, c.imz + imz};
    }

    friend std::ostream & operator<<(std::ostream &os, const Complex &obj) {
        return os << obj.rez << ',' << obj.imz << std::endl;
    }
private:
    double rez;
    double imz;
};

int main() {
    std::cout << Complex(1, 2) + Complex(2, -1) << std::endl;
}
