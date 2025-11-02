//
// Created by PC on 2025/11/2.
//

#include <iostream>

#include "ThreadPool.h"

int main() {
    ThreadPool pool(5);
    pool.Start();
    std::vector<std::future<int>> futures;
    int size = 15;
    futures.reserve(size);
    for (int i = 0; i < size; ++i) {
        futures.push_back(pool.EnqueueReturnable([](int a) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            return a;
        }, i));
    }
    for (auto& f : futures) {
        std::cout << f.get() << ' ';
    }
    std::cout << std::endl;
    return 0;
}
