//
// Created by PC on 2025/11/2.
//

#include <cmath>
#include <cstring>
#include <future>
#include <iostream>
#include <vector>

//获得[2,n]的所有素数
std::vector<int> GetPrimes(int n) {
    int end = static_cast<int>(std::floor(std::sqrt(n)));
    bool is_prime[n + 1];
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i <= end; ++i) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    std::vector<int> result;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    std::packaged_task task([](int i) {
        return GetPrimes(i);
    });
    auto future = task.get_future();
    int n = 50;
    std::thread thread(std::move(task), n); //开始计算
    const auto& result = future.get(); //阻塞，并获取计算结果
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    if (thread.joinable()) {
        thread.join();  //回收线程，否则会报错"terminate called without an active exception"
    }
    return 0;
}