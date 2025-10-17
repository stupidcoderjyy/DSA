//
// Created by PC on 2025/10/17.
//

#include "Manager.h"
#include "Student.h"

int main() {
    {
        StudentManager manager;
        manager.Create("a", "aaa", 10, 12.5f, Class::A);
        manager.Create("b", "bbbb", 20, 30.6f, Class::B);
        manager.Create("c", "cccc", 20, 30.6f, Class::B);
        manager.Create("c", "cccc", 20, 30.6f, Class::B);
    }
}
