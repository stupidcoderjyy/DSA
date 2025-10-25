//
// Created by PC on 2025/10/25.
//

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<>> queue;
    std::vector vec{3, 1, 4, 1, 5, 9, 2};
    for (const int& num : vec) {
        queue.push(num);
    }
    while (!queue.empty()) {
        std::cout << queue.top() << " ";
        queue.pop();
    }
    std::cout << '\n';
}
