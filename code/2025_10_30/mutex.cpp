//
// Created by PC on 2025/10/30.
//

#include <iostream>
#include <mutex>
#include <thread>

int main() {
    int val = 0;
    std::mutex mutex;
    std::thread t1([&] {
        for (int i = 0; i < 1000000; ++i) {
            std::lock_guard lock(mutex);
            val++;
        }
    }), t2([&] {
        for (int i = 0; i < 1000000; ++i) {
            std::lock_guard lock(mutex);
            val++;
        }
    });
    t1.join();
    t2.join();
    std::cout << val << std::endl;
    return 0;
}
