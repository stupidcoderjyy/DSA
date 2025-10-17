//
// Created by PC on 2025/10/17.
//

#ifndef DSA_MANAGER_H
#define DSA_MANAGER_H

#include <unordered_map>

#include "Student.h"

class StudentManager {
public:
    StudentManager();
    ~StudentManager();
    void Create(const std::string &id, const std::string &name, int age, float score, Class clazz);
private:
    void Close();
    void Save() const;
    void Load();
    std::unordered_map<std::string, Student*> students_;
};

#endif //DSA_MANAGER_H