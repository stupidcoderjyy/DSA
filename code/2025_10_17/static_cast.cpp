//
// Created by stupid_coder_jyy on 25-10-18.
//

#include <iostream>

class Base {
public:
    int val_base_ = 10;
};

class Derived : public Base {
public:
    int val_derived = 20;
};

int main() {
    Derived d;
    Base* b = &d;
    std::cout << b->val_base_ << std::endl;
    auto* p = static_cast<Derived*>(b);
    std::cout << p->val_derived << std::endl;
}