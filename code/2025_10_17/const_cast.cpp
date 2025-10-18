//
// Created by stupid_coder_jyy on 25-10-18.
//

#include <iostream>

class A {
public:
    explicit A(int val): kVal_(val) {}

    const int& get_val() const {
        return kVal_;
    }
private:
    const int kVal_;
};

int main() {
    A a(10);
    std::cout << a.get_val() << std::endl;
    const_cast<int&>(a.get_val()) = 15;
    std::cout << a.get_val() << std::endl;
}