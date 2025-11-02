//
// Created by PC on 2025/11/2.
//

#include <future>
#include <iostream>
#include <thread>

int main() {
    std::promise<int> promise;
    auto future = promise.get_future();
    std::thread thread([&promise] {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        promise.set_value(100);
    });
    std::cout << future.get() << std::endl;
    if (thread.joinable()) {
        thread.join();
    }
}
