//
// Created by PC on 2025/10/21.
//

#include <iostream>

class ScoopedPtr {
public:
    explicit ScoopedPtr(int val): data_(new int[]{val}) {
        std::cout << "create " << data_ << '\n';
    }
    ScoopedPtr(const ScoopedPtr&) = delete;
    ScoopedPtr& operator=(const ScoopedPtr&) = delete;

    ~ScoopedPtr() {
        std::cout << "delete " << data_ << '\n';
        delete[] data_;
    }

    ScoopedPtr(ScoopedPtr&& o) noexcept {
        data_ = o.data_;
        o.data_ = nullptr;
    }

    ScoopedPtr& operator=(ScoopedPtr&& o) noexcept {
        if (this == &o) {
            return *this;
        }
        if (data_) {
            std::cout << "delete " << data_ << '\n';
            delete[] data_;
        }
        data_ = o.data_;
        o.data_ = nullptr;
        return *this;
    }

    int* get_data() const {
        return data_;
    }
private:
    int* data_{};
};

int main() {
    ScoopedPtr p1(1);
    ScoopedPtr p2(2);
    p1 = std::move(p2);
    std::cout << p1.get_data() << '\n';
    std::cout << p2.get_data() << std::endl;
}