//
// Created by PC on 2025/10/30.
//

#include <condition_variable>
#include <deque>
#include <iostream>
#include <thread>

std::mutex mutex;
std::deque<int> deque;
int count = 0;
constexpr int kMaxCount = 200;

void Consume() {
    do {
        std::unique_lock lock(mutex);
        if (deque.empty()) {
            continue;
        }
        std::cout << "<< ";
        while (!deque.empty()) {
            std::cout << deque.front() << ' ';
            deque.pop_front();
            count++;
        }
        std::cout << "\n";
    } while (count < kMaxCount);
}

void Supply() {
    for (int i = 0; i < kMaxCount; ++i) {
        std::unique_lock lock(mutex);
        deque.push_back(i);
    }
}

int main() {
    std::thread consumer(&Consume), supplier(&Supply);
    if (consumer.joinable()) {
        consumer.join();
    }
    if (supplier.joinable()) {
        supplier.join();
    }
    return 0;
}
