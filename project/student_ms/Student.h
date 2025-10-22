//
// Created by PC on 2025/10/17.
//

#ifndef DSA_STUDENT_H
#define DSA_STUDENT_H

#include <string>
#include <vector>

namespace ms {

    typedef const std::string& KStrRef;

    class Student {
    public:
        static constexpr int kIdSize = 10;
        static constexpr int kNameSize = 20;
        static int allocated;

        Student();
        ~Student();

        inline std::string get_id() const;
        void set_id(KStrRef id);
        inline std::string get_name() const;
        void set_name(KStrRef new_name);
        inline int get_age() const;
        inline void set_age(KStrRef new_age);
        inline float get_score() const;
        inline void set_score(KStrRef new_score);
        std::string get_clazz() const;
        void set_clazz(KStrRef new_clazz);

        friend std::ostream & operator<<(std::ostream &os, const Student &obj);
        static Student* Create(KStrRef id, KStrRef name, KStrRef age, KStrRef score, KStrRef clazz);
        static void Print(std::ostream& os, KStrRef id, KStrRef name, KStrRef age, KStrRef score, KStrRef clazz);
        static void PrintTitle(std::ostream &os);
        static void PrintStudents(std::ostream &os, const std::vector<Student*>& students) ;
    private:
        char id_[kIdSize]{};
        char name_[kNameSize]{};
        int age_;
        float score_;
        enum class Class {
            A, B, C
        } clazz_;
    };

    std::string Student::get_id() const {
        return {id_};
    }

    std::string Student::get_name() const {
        return {name_};
    }

    int Student::get_age() const {
        return age_;
    }

    void Student::set_age(KStrRef new_age) {
        this->age_ = std::stoi(new_age);
    }

    float Student::get_score() const {
        return score_;
    }

    void Student::set_score(KStrRef new_score) {
        this->score_ = std::stof(new_score);
    }

}

#endif //DSA_STUDENT_H