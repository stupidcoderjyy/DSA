//
// Created by stupid_coder_jyy on 25-10-18.
//

#include <iostream>

class Base {
public:
    virtual void Func() {
        std::cout << "Base" << std::endl;
    }
};

class Derived : public Base {
public:
    void Func() override {
        std::cout << "Derived" << std::endl;
    }
};

int main() {
    Derived d;
    d.Func();
    Base* b = &d;
    b->Func();
    auto* p_derived = dynamic_cast<Derived*>(b);
    p_derived->Func();
}