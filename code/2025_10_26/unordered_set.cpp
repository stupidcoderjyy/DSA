//
// Created by PC on 2025/10/25.
//

#include <chrono>
#include <iostream>
#include <random>
#include <set>
#include <unordered_set>
#include <vector>

bool Func(std::unordered_set<int>& set, int key) {
    if (set.find(key) == set.end()) {
        return false;
    }
    set.erase(key);
    return true;
}

auto CurrentTimeMills() {
    using std::chrono::milliseconds;
    using std::chrono::system_clock;
    return std::chrono::duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int main() {
    std::unordered_set set{1, 5, 3, 9, 7};
    std::cout << Func(set, 1) << '\n';
    std::cout << Func(set, 1) << '\n';

    std::default_random_engine ran;
    std::uniform_int_distribution d(INT_MIN, INT_MAX);
    ran.seed(time(nullptr));

    std::vector<int> nums(100000);
    for (int& num : nums) {
        num = d(ran);
    }
    std::set<int> set_1;
    std::unordered_set<int> set_2;

    std::cout << "insert: ";
    auto t = CurrentTimeMills();
    for (const int& num : nums) {
        set_1.insert(num);
    }
    std::cout << CurrentTimeMills() - t << ' ';
    t = CurrentTimeMills();
    for (const int& num : nums) {
        set_2.insert(num);
    }
    std::cout << CurrentTimeMills() - t << '\n';

    std::cout << "find: ";
    t = CurrentTimeMills();
    for (int i = 0; i < 100000; ++i) {
        set_1.find(i);
    }
    std::cout << CurrentTimeMills() - t << ' ';
    t = CurrentTimeMills();
    for (int i = 0; i < 100000; ++i) {
        set_2.find(i);
    }
    std::cout << CurrentTimeMills() - t << '\n';

    std::cout << "traverse: ";
    t = CurrentTimeMills();
    size_t sum = 0;
    for (int i : set_1) {
        sum += i;
    }
    std::cout << CurrentTimeMills() - t << ' ';
    t = CurrentTimeMills();
    sum = 0;
    for (int i : set_2) {
        sum += i;
    }
    std::cout << CurrentTimeMills() - t << '\n';
}
