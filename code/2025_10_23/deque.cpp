//
// Created by PC on 2025/10/23.
//

#include <deque>
#include <iostream>

void PushFrontAndDouble(std::deque<int>& deque, int n) {
    deque.push_front(n);
    for (int& num : deque) {
        num *= 2;
    }
}

int main() {
    std::deque<int> deque;
    for (int i = 1; i <= 5; ++i) {
        deque.push_back(i);
    }
    for (int num : deque) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    std::cout << deque[2] << '\n';

    for (int i = 1; i <= 5; ++i) {
        int val;
        if (i & 1) {
            val = deque.back();
            deque.pop_back();
        } else {
            val = deque.front();
            deque.pop_front();
        }
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
