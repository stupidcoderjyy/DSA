//
// Created by PC on 2025/11/2.
//

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

int main() {
    std::vector times{2, 3, 4};
    std::atomic<int> counter{};
    std::thread threads[times.size()];
    for (int i = 0; i < times.size(); ++i) {
        threads[i] = std::thread([i, &times, &counter] {
            for (int j = 0; j < times[i]; ++j) {
                ++counter;
            }
        });
    }
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    std::cout << counter << std::endl;
    return 0;
}
