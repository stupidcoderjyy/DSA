//
// Created by PC on 2025/10/17.
//

#ifndef DSA_STUDENT_H
#define DSA_STUDENT_H

#include <string>

namespace ms {

    class Student {
    public:
        Student();

        inline std::string get_id() const;
        void set_id(const std::string& id);
        inline std::string get_name() const;
        void set_name(const std::string& new_name);
        inline int get_age() const;
        inline void set_age(int new_age);
        inline float get_score() const;
        inline void set_score(float new_score);
        std::string get_clazz() const;
        void set_clazz(const std::string& new_clazz);

        std::string ToString() const;
        static Student* Create(const std::string &id, const std::string &name, int age, float score, const std::string& clazz);
    private:

        static constexpr int kIdSize = 10;
        static constexpr int kNameSize = 20;
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

    void Student::set_age(int new_age) {
        this->age_ = new_age;
    }

    float Student::get_score() const {
        return score_;
    }

    void Student::set_score(float new_score) {
        this->score_ = new_score;
    }

}

#endif //DSA_STUDENT_H