//
// Created by PC on 2025/10/21.
//

#include <iostream>
#include <string>

class StringWrapper {
public:
    explicit StringWrapper(std::string str): str_(std::move(str)) {}
    StringWrapper(const StringWrapper& sw) = default;
    StringWrapper(StringWrapper&& sw) noexcept {
        str_ = std::move(sw.str_);
    }
    void PrintStr() const {
        std::cout << str_ << std::endl;
    }
private:
    std::string str_;
};

int main() {
    StringWrapper s1("111");
    StringWrapper s2(s1);
    s1.PrintStr();
    s2.PrintStr();

    StringWrapper s3(std::move(s2));
    s2.PrintStr();
    s3.PrintStr();
}