//
// Created by PC on 2025/10/11.
//

class A {
public:
    A() : data_(new int[10]) {}

    ~A() {
        delete[] data_;
    }
private:
    int* data_;
};
