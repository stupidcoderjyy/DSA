//
// Created by PC on 2025/10/16.
//

#include <iostream>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void MakeSound() = 0;
};

class Dog : public Animal {
public:
    void MakeSound() override {
        std::cout << "Dog" << std::endl;
    }
};

class Cat : public Animal {
public:
    void MakeSound() override {
        std::cout << "Cat" << std::endl;
    }
};

int main() {
    Animal* animals[] = {new Dog, new Cat, new Dog};
    for (auto a : animals) {
        a->MakeSound();
        delete a;
    }
}
