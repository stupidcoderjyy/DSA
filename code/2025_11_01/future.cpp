//
// Created by PC on 2025/11/2.
//

#include <future>
#include <iostream>

typedef std::tuple<long long, long long> Result;

long long Fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    auto a = 1LL, b = 1LL;
    for (int i = 2; i <= n; ++i) {
        auto c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 9;
    auto future = std::async([&] {
        auto start = std::chrono::high_resolution_clock::now();
        auto result = Fib(n);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        return Result{result, duration};
    });
    auto[r,  d] = future.get();
    std::cout << d << "ns " << r << std::endl;
}
