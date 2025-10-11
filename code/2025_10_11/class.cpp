//
// Created by PC on 2025/10/11.
//

#include <iostream>
#include <string>

class Student {
public:
    Student(const std::string &name, int age, const std::string &id)
        : name_(name), age_(age), id_(id) {
    }

    void Display() const {
        std::cout << name_ << " " << age_ << " " << id_ << std::endl;
    }

    std::string name() const {
        return name_;
    }

    void set_name(const std::string &name) {
        name_ = name;
    }

    int age() const {
        return age_;
    }

    void set_age(int age) {
        age_ = age;
    }

    std::string id() const {
        return id_;
    }

    void set_id(const std::string &id) {
        id_ = id;
    }

private:
    std::string name_;
    int age_;
    std::string id_;
};

int main() {
    Student a("A", 10, "1"), b("B", 20, "2");
    a.set_id("aaaaa");
    b.set_name("BBB");
    a.Display();
    b.Display();
}
