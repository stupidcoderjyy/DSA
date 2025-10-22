//
// Created by PC on 2025/10/17.
//

#ifndef DSA_MANAGER_H
#define DSA_MANAGER_H

#include <functional>
#include <vector>

#include "Log.h"
#include "Student.h"

namespace ms {

    typedef std::vector<Student*> StuVec;

    class StudentManager {
    public:
        explicit StudentManager(Logger& logger);
        ~StudentManager();
        void Load(KStrRef file);
        void Create(KStrRef id, KStrRef name, KStrRef age, KStrRef score, KStrRef clazz);
        void Remove(KStrRef id);
        void Modify(KStrRef id, KStrRef key, KStrRef val);
        void Search(KStrRef type, KStrRef arg) const;
        void Sort(KStrRef type, bool print);
        void Close();
        void Save();
        void Print() const;
    private:
        static void ModifyName(Student* s, KStrRef val);
        static void ModifyAge(Student* s, KStrRef val);
        static void ModifyScore(Student* s, KStrRef val);
        static void ModifyClazz(Student* s, KStrRef val);
        Logger& log_;
        StuVec students_;
        bool dirty_;
    };

    class Searcher {
        friend class StudentManager;
    private:
        typedef std::function<bool(const Student&, KStrRef arg)> Predicate;
        static StuVec SearchBy(const StuVec& src, KStrRef type, KStrRef key);
        static StuVec Collect(const StuVec& src, KStrRef arg, const Predicate& pred);
        static StuVec SearchById(const StuVec& src, KStrRef key);
        static StuVec SearchByName(const StuVec& src, KStrRef key);
        static StuVec SearchByScore(const StuVec& src, KStrRef key);
        static StuVec SearchByClass(const StuVec& src, KStrRef key);
    };

    class Sorter {
        friend class StudentManager;
    private:
         static void SortBy(StuVec& src, KStrRef type);
    };

}


#endif //DSA_MANAGER_H