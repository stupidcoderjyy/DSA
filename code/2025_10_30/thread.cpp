//
// Created by PC on 2025/10/30.
//

#include <iostream>
#include <thread>

int main() {
    std::thread t1([] {
        std::cout << "1\n";
    }), t2([] {
        std::cout << "2\n";
    }), t3([] {
        std::cout << "3\n";
    });
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
