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

namespace ms {

    StudentManager::StudentManager(): log("system.log") {
        Load("students.dat");
    }

    StudentManager::~StudentManager() {
        Close();
    }

    void StudentManager::Load(const std::string& file) {
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
        }
    }

    void StudentManager::Create(const std::string &id, const std::string &name, int age, float score, const std::string& clazz) {
        try {
            auto it = std::ranges::find_if(students_, [&](Student* s) {
                return s->get_id() == id;
            });
            if (it != students_.end()) {
                throw std::runtime_error("id '" + id + "' has already been registered");
            }
            auto* s = Student::Create(id, name, age, score, clazz);
            students_.push_back(s);
            log.info() << "registered: " << '\n' << s << std::endl;
        } catch (std::runtime_error& e) {
            log.error() << "failed to register: " << e.what() << std::endl;
        }
    }

    void StudentManager::Remove(const std::string &id) {
        try {
            auto it = std::ranges::find_if(students_, [&](Student* s) {
                return s->get_id() == id;
            });
            if (it == students_.end()) {
                throw std::runtime_error("id '" + id + "' not found");
            }
            students_.erase(it);
            log.info() << "removed: '" << id << "'" << std::endl;
        } catch (std::runtime_error& e) {
            log.error() << "failed to remove: " << e.what() << std::endl;
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
            auto it = std::ranges::find_if(students_, [&](Student* s) {
                return s->get_id() == id;
            });
            if (it == students_.end()) {
                throw std::runtime_error("id '" + id + "' not found");
            }
            std::string err;
            handlers[key](*it, val);
            log.info() << "modified: " << '\n' << *it << std::endl;
        } catch (std::runtime_error& e) {
            log.info() << "failed to modify: " << e.what() << std::endl;
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
        for (const auto &s: students_) {
            delete s;
        }
        students_ = {};
    }

    void StudentManager::Save() const {
        std::ofstream os("students.dat", std::ios::binary);
        os << students_.size();
        for (const auto &val: students_) {
            os.write(reinterpret_cast<char*>(val), sizeof(Student));
        }
        os.close();
    }

    Searcher::StuVec Searcher::SearchBy(const StuVec& src, const std::string &type, const std::string &key) {
        typedef std::unordered_map<std::string, std::function<StuVec(const StuVec&, const std::string&)>> Searchers;
        static Searchers searchers {
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

    static int LevenshteinDistance(const std::string& s1, const std::string& s2) {
        int rows = s1.length(), columns = s2.length();
        int dp[rows][columns];
        for (int i = 0; i < rows; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j < columns; ++j) {
            dp[0][j] = j;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
            }
        }
        return dp[rows - 1][columns - 1];
    }

    Searcher::StuVec Searcher::SearchById(const StuVec& src, const std::string &key) {
        StuVec result;
        for (const auto& s : src) {
            if (LevenshteinDistance(s->get_id(), key) < 4) {
                result.push_back(s);
            }
        }
        return result;
    }

    std::vector<Student*> Searcher::SearchByName(const StuVec& src, const std::string &key) {
    }

    std::vector<Student*> Searcher::SearchByScore(const StuVec& src, const std::string &key) {
    }

    std::vector<Student*> Searcher::SearchByClass(const StuVec& src, const std::string &key) {
    }
}
