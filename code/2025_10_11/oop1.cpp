//
// Created by PC on 2025/10/11.
//

#include <iostream>
#include <ostream>
#include <string>

class Person {
public:
    Person(const std::string &name, int age) : name_(name), age_(age) {}
    ~Person() = default;

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

private:
    std::string name_;
    int age_;
};


class Student : public Person {
public:
    Student(const std::string &name, int age, int student_id)
            : Person(name, age), student_id_(student_id) {
    }

    int student_id() const {
        return student_id_;
    }

    void set_student_id(int student_id) {
        student_id_ = student_id;
    }

private:
    int student_id_;
};

int main() {
    Person p("p1", 10);
    p.set_age(12);
    std::cout << p.name() << " " << p.age() << '\n';

    Student s("s1", 10, 1);
    s.set_student_id(2);
    std::cout << s.name() << " " << s.age() << " " << s.student_id() << std::endl;
    return 0;
}