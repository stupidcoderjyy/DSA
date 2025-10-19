//
// Created by PC on 2025/10/19.
//

#include <cstring>
#include <iostream>

class MyClass {
public:
    MyClass(): data_(new int[2]) {
        std::cout << "constructor\n";
        std::srand(time(nullptr));
        for (int i = 0; i < 2; ++i) {
            data_[i] = std::rand() % 10;
        }
    }

    MyClass(const MyClass& other) {
        std::cout << "constructor copy\n";
        data_ = new int[2];
        memcpy(data_, other.data_, 2 * sizeof(int));
    }

    MyClass(MyClass&& other) noexcept {
        std::cout << "constructor move\n";
        data_ = other.data_;
        other.data_ = nullptr;
    }

    MyClass& operator=(const MyClass &other) {
        std::cout << "operator copy\n";
        if (this == &other) {
            return *this;
        }
        if (data_ && other.data_) {
            memcpy(data_, other.data_, 2 * sizeof(int));
        } else if (data_) {
            std::cout << "delete " << data_ << '\n';
            delete[] data_;
            data_ = nullptr;
        } else {
            data_ = new int[2];
            memcpy(data_, other.data_, 2 * sizeof(int));
        }
        return *this;
    }

    MyClass& operator=(MyClass &&other) noexcept {
        std::cout << "operator move\n";
        if (this == &other) {
            return *this;
        }
        if (data_) {
            std::cout << "delete " << data_ << '\n';
            delete[] data_;
        }
        data_ = other.data_;
        other.data_ = nullptr;
        return *this;
    }

    ~MyClass() {
        std::cout << "delete " << data_ << '\n';
        delete[] data_;
    }

    void PrintData(const std::string& name) const {
        std::cout << name << ": " << data_;
        if (data_) {
            std::cout << " [" << data_[0] << "," << data_[1] << "]";
        }
        std::cout << '\n';
    }
private:
    int* data_{};
};

int main() {
    std::cout << "\nMyClass c1; MyClass c2 = c1;\n";
    MyClass c1;
    MyClass c2 = c1;
    c1.PrintData("c1");
    c2.PrintData("c2");

    std::cout << "\nMyClass c3 = std::move(c1);\n";
    MyClass c3 = std::move(c1);
    c1.PrintData("c1");
    c3.PrintData("c3");

    std::cout << "\nc1 = c3;\n";
    c1 = c3;
    c1.PrintData("c1");
    c3.PrintData("c3");

    std::cout << "\nc1 = std::move(c3);\n";
    c1 = std::move(c3);
    c1.PrintData("c1");
    c3.PrintData("c3");
}


