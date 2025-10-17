//
// Created by PC on 2025/10/17.
//

#include "Manager.h"

#include <fstream>
#include <iosfwd>
#include <iostream>
#include <ranges>

StudentManager::StudentManager() {
    Load();
}

StudentManager::~StudentManager() {
    Close();
}

void StudentManager::Create(const std::string &id, const std::string &name, int age, float score, Class clazz) {
    try {
        if (students_.contains(id)) {
            throw std::runtime_error("id '" + id + "' has already been registered");
        }
        auto* s = Student::create(id, name, age, score, clazz);
        students_[s->get_id()] = s;
    } catch (std::runtime_error& e) {
        std::cerr << "Failed to create student: " << e.what() << std::endl;
    }
}

void StudentManager::Close() {
    Save();
    for (const auto &s: students_ | std::views::values) {
        delete s;
    }
    students_ = {};
}

void StudentManager::Save() const {
    std::ofstream os("students.dat", std::ios::binary);
    os << students_.size();
    for (const auto &val: students_ | std::views::values) {
        os.write(reinterpret_cast<char*>(val), sizeof(Student));
    }
    os.close();
}

void StudentManager::Load() {
    std::ifstream is("students.dat", std::ios::binary);
    if (is.peek() == EOF) {
        return;
    }
    size_t size;
    is >> size;
    students_.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        auto* p = static_cast<char*>(malloc(sizeof(Student)));
        is.read(p, sizeof(Student));
        auto* s = reinterpret_cast<Student*>(p);
        students_[s->get_id()] = s;
    }
}