//
// Created by PC on 2025/10/17.
//

#include <cstring>
#include <stdexcept>
#include <iomanip>

#include "Student.h"

namespace ms {

    Student::Student() : age_(), score_(), clazz_() {}

    void Student::set_id(const std::string &new_id) {
        if (new_id.size() > kIdSize) {
            throw std::runtime_error("invalid id: '" + new_id + "'");
        }
        memset(this->id_, 0, kIdSize);
        strncpy(this->id_, new_id.c_str(), new_id.size());
    }

    void Student::set_name(const std::string &new_name) {
        if (new_name.size() > kNameSize) {
            throw std::runtime_error("invalid name: '" + new_name + "'");
        }
        memset(this->name_, 0, kNameSize);
        strncpy(this->name_, new_name.c_str(), new_name.size());
    }

    std::string Student::get_clazz() const {
        switch (clazz_) {
            case Class::A:
                return "A";
            case Class::B:
                return "B";
            case Class::C:
                return "C";
            default:
                return "Invalid Class";
        }
    }

    void Student::set_clazz(const std::string &new_clazz) {
        if (new_clazz == "A") {
            clazz_ = Class::A;
        } else if (new_clazz == "B") {
            clazz_ = Class::B;
        } else if (new_clazz == "C") {
            clazz_ = Class::C;
        } else {
            throw std::runtime_error("invalid class: '" + new_clazz + "'");
        }
    }

    std::ostream& operator<<(std::ostream &os, const Student &obj) {
        os << std::setw(Student::kIdSize) << std::left << obj.get_id();
        os << std::setw(Student::kNameSize) << std::left << obj.get_name();
        os << std::setw(5) << std::left << obj.get_age();
        os << std::setw(5) << std::left << obj.get_score();
        os << std::setw(5) << std::left << obj.get_clazz();
        return os;
    }

    Student* Student::Create(const std::string &id, const std::string &name, int age, float score, const std::string& clazz) {
        Student* s = nullptr;
        try {
            s = new Student;
            s->set_id(id);
            s->set_name(id);
            s->set_age(age);
            s->set_score(score);
            s->set_clazz(clazz);
        } catch (std::runtime_error&) {
            delete s;
            throw;
        }
        return s;
    }

}
