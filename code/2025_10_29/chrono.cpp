//
// Created by PC on 2025/10/30.
//

#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <bits/this_thread_sleep.h>

using std::chrono::time_point;
using std::chrono::high_resolution_clock;
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration;
using std::chrono::duration_cast;

void Func1() {
    auto start = high_resolution_clock::now();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::seconds>(end - start);
    std::cout << duration.count() << "s\n";
}

long double StandardDeviation(const std::vector<long double>& vec) {
    long double avr = std::accumulate(vec.begin(), vec.end(), 0.0L) / static_cast<double>(vec.size());
    long double res = 0;
    for (const auto& v : vec) {
        res += std::pow(v - avr, 2);
    }
    return std::sqrt(res / vec.size());
}

void Func2() {
    std::vector<long double> vec;
    int count = 100;
    vec.reserve(count);
    for (int i = 0; i < count; ++i) {
        auto d = system_clock::now() - system_clock::now();
        vec.push_back(d.count());
    }
    std::cout << StandardDeviation(vec) << '\n';
    vec.clear();
    for (int i = 0; i < count; ++i) {
        auto d = steady_clock::now() - steady_clock::now();
        vec.push_back(d.count());
    }
    std::cout << StandardDeviation(vec) << '\n';
}

void Func3() {
    auto time = system_clock::to_time_t(system_clock::now());
    auto local_time = std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(local_time, "%Y-%m-%d %H:%M:%S");
    std::cout << oss.str() << '\n';
}

int main() {
    Func1();
    Func2();
    Func3();
    return 0;
}