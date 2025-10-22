//
// Created by PC on 2025/10/17.
//

#include <cstring>
#include <stdexcept>
#include <iomanip>

#include "Student.h"

namespace ms {

    Student::Student() : age_(), score_(), clazz_() {
        allocated++;
    }

    Student::~Student() {
        allocated--;
    }

    void Student::set_id(KStrRef new_id) {
        if (new_id.size() > kIdSize) {
            throw std::runtime_error("invalid id: '" + new_id + "'");
        }
        memset(this->id_, 0, kIdSize);
        strncpy(this->id_, new_id.c_str(), new_id.size());
    }

    void Student::set_name(KStrRef new_name) {
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

    void Student::set_clazz(KStrRef new_clazz) {
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
        char score_ch[10];
        sprintf(score_ch, "%.f", obj.get_score());
        Student::Print(os,
            obj.get_id(),
            obj.get_name(),
            std::to_string(obj.get_age()),
            std::string(score_ch),
            obj.get_clazz());
        return os;
    }

    void Student::Print(std::ostream &os, KStrRef id, KStrRef name, KStrRef age, KStrRef score, KStrRef clazz) {
        os << std::setw(kIdSize) << std::left << id;
        os << std::setw(kNameSize) << std::left << name;
        os << std::setw(7) << std::left << age;
        os << std::setw(10) << std::left << score;
        os << std::setw(10) << std::left << clazz;
    }

    void Student::PrintTitle(std::ostream &os) {
        Print(os, "ID", "NAME", "AGE", "SCORE", "CLASS");
    }

    void Student::PrintStudents(std::ostream &os, const std::vector<Student *> &students) {
        os << '\n';
        PrintTitle(os);
        for (auto s : students) {
            os << '\n' << *s;
        }
        os << std::endl;
    }

    Student* Student::Create(KStrRef id, KStrRef name, KStrRef age, KStrRef score, KStrRef clazz) {
        Student* s = nullptr;
        try {
            s = new Student;
            s->set_id(id);
            s->set_name(name);
            s->set_age(age);
            s->set_score(score);
            s->set_clazz(clazz);
        } catch (std::runtime_error&) {
            delete s;
            throw;
        }
        return s;
    }

    int Student::allocated{};

}
