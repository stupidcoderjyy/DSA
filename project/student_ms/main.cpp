//
// Created by PC on 2025/10/17.
//

#include "Manager.h"
#include "Student.h"


int main() {
    {
        ms::StudentManager manager;
        manager.Create("a", "aaa", 10, 12.5f, "A");
        manager.Create("b", "bbbb", 20, 30.6f, "B");
        manager.Create("c", "cccc", 20, 30.6f, "C");
        manager.Create("c", "cccc", 20, 30.6f, "D");
        manager.Remove("c");
        manager.Remove("c");
        manager.Modify("a", "name", "a2");
    }
}
