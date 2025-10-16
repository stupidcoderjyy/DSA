//
// Created by PC on 2025/10/16.
//

#include <iostream>
#include <vector>

class Counter {
public:
    Counter() {
        obj_count++;
    }

    static int ObjCount() {
        return obj_count;
    }
private:
    static int obj_count;
};

int Counter::obj_count = 0;

int main() {
    std::vector<Counter> vec(5);
    std::cout << Counter::ObjCount() << std::endl;
}