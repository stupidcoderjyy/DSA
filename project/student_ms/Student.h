//
// Created by PC on 2025/10/17.
//

#ifndef DSA_STUDENT_H
#define DSA_STUDENT_H
#include <string>

enum class Class {
    A, B, C
};

struct Student {
    static constexpr int kIdSize = 10;
    static constexpr int kNameSize = 20;
    char id[kIdSize]{};
    char name[kNameSize]{};
    int age;
    float score;
    Class clazz;

    std::string get_id() const {
        return {id};
    }

    std::string get_name() const {
        return {name};
    }

    static Student* create(const std::string &id, const std::string &name, int age, float score, Class clazz);
};

#endif //DSA_STUDENT_H