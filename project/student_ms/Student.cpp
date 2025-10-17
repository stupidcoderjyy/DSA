//
// Created by PC on 2025/10/17.
//

#include "Student.h"

#include <cstring>
#include <iostream>
#include <stdexcept>

Student* Student::create(const std::string &id, const std::string &name, int age, float score, Class clazz) {
    if (id.size() > kIdSize) {
        throw std::runtime_error("invalid id '" + id + "'");
    }
    if (name.size() > kNameSize) {
        throw std::runtime_error("invalid name: '" + name + "'");
    }
    auto* s = new Student;
    strncpy(s->id, id.c_str(), id.size());
    strncpy(s->name, name.c_str(), name.size());
    s->age = age;
    s->score = score;
    s->clazz = clazz;
    return s;
}
