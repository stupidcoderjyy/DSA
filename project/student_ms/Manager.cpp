//
// Created by PC on 2025/10/17.
//

#include <fstream>
#include <iosfwd>
#include <iostream>
#include <ranges>

#include "Manager.h"

namespace ms {

    StudentManager::StudentManager() {
        Load();
    }

    StudentManager::~StudentManager() {
        Close();
    }

    void StudentManager::Create(const std::string &id, const std::string &name, int age, float score, const std::string& clazz) {
        try {
            if (students_.contains(id)) {
                throw std::runtime_error("id '" + id + "' has already been registered");
            }
            auto* s = Student::Create(id, name, age, score, clazz);
            students_[s->get_id()] = s;
            log.Info("registered: %s", s->ToString().c_str());
        } catch (std::runtime_error& e) {
            log.Error("failed to register: %s", e.what());
        }
    }

    void StudentManager::Remove(const std::string &id) {
        try {
            if (!students_.contains(id)) {
                throw std::runtime_error("id '" + id + "' not found");
            }
            students_.erase(id);
            log.Info("removed: '%s'", id.c_str());
        } catch (std::runtime_error& e) {
            log.Error("failed to remove: %s", e.what());
        }
    }

    void StudentManager::Modify(const std::string &id, const std::string& key, const std::string &val) {
        static std::unordered_map<std::string,  void (*)(Student*, const std::string&)> handlers = {
            {"name", &StudentManager::ModifyName},
            {"age", &StudentManager::ModifyAge},
            {"score", &StudentManager::ModifyScore},
            {"class", &StudentManager::ModifyClazz},
        };
        try {
            if (!handlers.contains(key)) {
                throw std::runtime_error("invalid option: '" + key + "'");
            }
            if (!students_.contains(id)) {
                throw std::runtime_error("id '" + id + "' not found");
            }
            std::string err;
            auto* s = students_[id];
            handlers[key](s, val);
            log.Info("modified: %s", s->ToString().c_str());
        } catch (std::runtime_error& e) {
            log.Error("failed to modify: %s", e.what());
        }
    }

    void StudentManager::ModifyName(Student *s, const std::string &val) {
        s->set_name(val);
    }

    void StudentManager::ModifyAge(Student *s, const std::string &val) {
        try {
            s->set_age(std::stoi(val));
        } catch (std::exception&) {
            throw std::runtime_error("invalid age: " + val);
        }
    }

    void StudentManager::ModifyScore(Student *s, const std::string &val) {
        try {
            s->set_score(std::stof(val));
        } catch (std::exception&) {
            throw std::runtime_error("invalid score: " + val);
        }
    }

    void StudentManager::ModifyClazz(Student *s, const std::string &val) {
        s->set_clazz(val);
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

}