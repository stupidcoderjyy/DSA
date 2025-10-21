//
// Created by PC on 2025/10/17.
//

#ifndef DSA_MANAGER_H
#define DSA_MANAGER_H

#include <functional>
#include <unordered_map>
#include <vector>

#include "Log.h"
#include "Student.h"

namespace ms {

    class StudentManager {
    public:
        StudentManager();
        ~StudentManager();
        void Load(const std::string& file);
        void Create(const std::string &id, const std::string &name, int age, float score, const std::string& clazz);
        void Remove(const std::string &id);
        void Modify(const std::string &id, const std::string& key, const std::string& val);
        void Search(const std::string& type, const std::function<void(std::vector<Student*>)>& consumer);
    private:
        static void ModifyName(Student* s, const std::string& val);
        static void ModifyAge(Student* s, const std::string& val);
        static void ModifyScore(Student* s, const std::string& val);
        static void ModifyClazz(Student* s, const std::string& val);
        Logger log;
        std::vector<Student*> students_;
        void Close();
        void Save() const;
    };

    class Searcher {
    public:
        typedef std::vector<Student*> StuVec;
        static StuVec SearchBy(const StuVec& src, const std::string& type, const std::string& key);
    private:
        static StuVec SearchById(const StuVec& src, const std::string& key);
        static StuVec SearchByName(const StuVec& src, const std::string& key);
        static StuVec SearchByScore(const StuVec& src, const std::string& key);
        static StuVec SearchByClass(const StuVec& src, const std::string& key);
    };

}


#endif //DSA_MANAGER_H