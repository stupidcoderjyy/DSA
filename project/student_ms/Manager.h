//
// Created by PC on 2025/10/17.
//

#ifndef DSA_MANAGER_H
#define DSA_MANAGER_H

#include <unordered_map>

#include "Log.h"
#include "Student.h"

namespace ms {

    class StudentManager {
    public:
        StudentManager();
        ~StudentManager();
        void Create(const std::string &id, const std::string &name, int age, float score, const std::string& clazz);
        void Remove(const std::string &id);
        void Modify(const std::string &id, const std::string& key, const std::string& val);
    private:
        Log log;
        static void ModifyName(Student* s, const std::string& val);
        static void ModifyAge(Student* s, const std::string& val);
        static void ModifyScore(Student* s, const std::string& val);
        static void ModifyClazz(Student* s, const std::string& val);
        void Close();
        void Save() const;
        void Load();
        std::unordered_map<std::string, Student*> students_;
    };

}


#endif //DSA_MANAGER_H