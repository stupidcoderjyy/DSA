//
// Created by PC on 2025/10/17.
//

#include <algorithm>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <ranges>

#include "Manager.h"

#include <algorithm>
#include <iomanip>

namespace ms {

    StudentManager::StudentManager(Logger& logger): log_(logger) {
        Load("students.dat");
        dirty_ = false;
    }

    StudentManager::~StudentManager() {
        Close();
    }

    void StudentManager::Load(KStrRef file) {
        std::ifstream is(file, std::ios::binary);
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
            students_.push_back(s);
            Student::allocated++;
        }
        dirty_ = true;
        log_.Info() << "Loaded " << size << " records" << std::endl;
    }

    void StudentManager::Create(KStrRef id, KStrRef name, KStrRef age, KStrRef score, KStrRef clazz) {
        auto it = std::ranges::find_if(students_, [&](Student* s) {
            return s->get_id() == id;
        });
        if (it != students_.end()) {
            throw std::runtime_error("id '" + id + "' has already been registered");
        }
        auto* s = Student::Create(id, name, age, score, clazz);
        students_.push_back(s);
        dirty_ = true;
        auto& log = log_.Info();
        log << "registered: " << '\n';
        Student::PrintTitle(log);
        log << '\n' << *s << std::endl;
    }

    void StudentManager::Remove(KStrRef id) {
        auto it = std::ranges::find_if(students_, [&](Student* s) {
            return s->get_id() == id;
        });
        if (it == students_.end()) {
            throw std::runtime_error("id '" + id + "' not found");
        }
        auto* s = *it;
        students_.erase(it);
        dirty_ = true;
        auto& log = log_.Info();
        log << "removed: ";
        Student::PrintStudents(log, {s});
        delete s;
    }

    void StudentManager::Modify(KStrRef id, KStrRef key, KStrRef val) {
        static std::unordered_map<std::string,  void (*)(Student*, KStrRef )> handlers = {
            {"name", &StudentManager::ModifyName},
            {"age", &StudentManager::ModifyAge},
            {"score", &StudentManager::ModifyScore},
            {"class", &StudentManager::ModifyClazz},
        };
        try {
            if (!handlers.contains(key)) {
                throw std::runtime_error("invalid option: '" + key + "'");
            }
            auto it = std::ranges::find_if(students_, [&](Student* s) {
                return s->get_id() == id;
            });
            if (it == students_.end()) {
                throw std::runtime_error("id '" + id + "' not found");
            }
            std::string err;
            handlers[key](*it, val);
            dirty_ = true;
            auto& log = log_.Info();
            log << "modified: ";
            Student::PrintStudents(log, {*it});
        } catch (std::runtime_error& e) {
            log_.Error() << "failed to modify: " << e.what() << std::endl;
        }
    }

    void StudentManager::Search(KStrRef type, KStrRef arg) const {
        try {
            Student::PrintStudents(log_.Info(), Searcher::SearchBy(students_, type, arg));
        } catch (std::exception& e) {
            log_.Error() << "failed to search type '" << type << "' with arg '" << arg << "':" << e.what();
        }
    }

    void StudentManager::Sort(KStrRef type, bool print) {
        try {
            Sorter::SortBy(students_, type);
            if (print) {
                Student::PrintStudents(log_.Info(), students_);
            }
        } catch (std::exception& e) {
            log_.Error() << "failed to sort by type '" << type << "':" << e.what() << std::endl;
        }
    }

    void StudentManager::Close() {
        Save();
        for (const auto &s: students_) {
            delete s;
        }
        students_ = {};
    }

    void StudentManager::Save() {
        if (!dirty_) {
            log_.Info() << "Everything uptodate" << std::endl;
            return;
        }
        std::ofstream os("students.dat", std::ios::binary);
        os << students_.size();
        for (const auto &val: students_) {
            os.write(reinterpret_cast<char*>(val), sizeof(Student));
        }
        os.close();
        dirty_ = false;
        log_.Info() << "Saved " << students_.size() << " records" << std::endl;
    }

    void StudentManager::Print() const {
        Student::PrintStudents(log_.Info(), students_);
    }

    void StudentManager::ModifyName(Student *s, KStrRef val) {
        s->set_name(val);
    }

    void StudentManager::ModifyAge(Student *s, KStrRef val) {
        try {
            s->set_age(val);
        } catch (std::exception&) {
            throw std::runtime_error("invalid age: " + val);
        }
    }

    void StudentManager::ModifyScore(Student *s, KStrRef val) {
        try {
            s->set_score(val);
        } catch (std::exception&) {
            throw std::runtime_error("invalid score: " + val);
        }
    }

    void StudentManager::ModifyClazz(Student *s, KStrRef val) {
        s->set_clazz(val);
    }

    StuVec Searcher::SearchBy(const StuVec& src, KStrRef type, KStrRef key) {
        typedef std::function<StuVec(const StuVec&, KStrRef )> Searcher;
        static std::unordered_map<std::string, Searcher> searchers {
            {"id", &SearchById},
            {"name", &SearchByName},
            {"score", &SearchByScore},
            {"class", &SearchByClass}
        };
        if (!searchers.contains(type)) {
            throw std::runtime_error("invalid searcher '" + type + "'");
        }
        return searchers[type](src, key);
    }

    StuVec Searcher::Collect(const StuVec &src, KStrRef arg, const Predicate &pred) {
        StuVec result;
        for (const auto& s : src) {
            if (pred(*s, arg)) {
                result.push_back(s);
            }
        }
        return result;
    }

    StuVec Searcher::SearchById(const StuVec& src, KStrRef key) {
        return Collect(src, key, [](const auto& stu, const auto& s) {
            auto id = stu.get_id();
            return id.find(s) < id.size();
        });
    }

    std::vector<Student*> Searcher::SearchByName(const StuVec& src, KStrRef key) {
        return Collect(src, key, [](const auto& stu, const auto& s) {
            auto name = stu.get_name();
            return name.find(s) < name.size();
        });
    }

    std::vector<Student*> Searcher::SearchByScore(const StuVec& src, KStrRef key) {
        return Collect(src, key, [](const auto& stu, const auto& s) {
            return std::abs(stu.get_score() - std::stoi(s)) < 10;
        });
    }

    std::vector<Student*> Searcher::SearchByClass(const StuVec& src, KStrRef key) {
        return Collect(src, key, [](const auto& stu, const auto& s) {
            return stu.get_clazz() == s;
        });
    }

    void Sorter::SortBy(StuVec& src, KStrRef type) {
        typedef bool (*Comp)(const Student* a, const Student* b);
        static std::unordered_map<std::string, Comp> sorters {
            {"id", [](auto a, auto b){ return a->get_id() < b->get_id();}},
            {"name", [](auto a, auto b){ return a->get_name() < b->get_name();}},
            {"score", [](auto a, auto b){ return a->get_score() < b->get_score();}},
            {"class", [](auto a, auto b){ return a->get_clazz() < b->get_clazz();}},
        };
        if (!sorters.contains(type)) {
            throw std::runtime_error("invalid sorter '" + type + "'");
        }
        std::ranges::sort(src, sorters[type]);
    }
}
