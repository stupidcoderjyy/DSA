//
// Created by PC on 2025/10/11.
//

#include <cstdio>
#include <iostream>

#define BUFFER_SIZE 10

struct Student {
    char name[10];
    int age;
};

Student students[] = {
    {"A", 1},
    {"B", 2},
    {"C", 3},
    {"D", 4},
};

int main() {
    FILE* f = fopen("students.dat", "w");
    if (!f) {
        perror("Failed to open file");
        return 1;
    }
    for (auto &[name, age] : students) {
        fprintf(f, "%s\n", name);
        fprintf(f, "%d\n", age);
    }
    fclose(f);
    f = fopen("students.dat", "r");
    for (int i = 0; i < 4; ++i) {
        Student s;
        fscanf(f, "%s", s.name);
        fscanf(f, "%d", &s.age);
        std::cout << s.name << ' ' << s.age << '\n';
    }
    std::cout << std::endl;
    if (ferror(f)) {
        perror("Failed to read file");
    }
    fclose(f);
}
