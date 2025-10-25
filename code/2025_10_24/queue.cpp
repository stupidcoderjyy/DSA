//
// Created by PC on 2025/10/25.
//

#include <iostream>
#include <queue>

int main() {
    std::queue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << queue.size() << " " << queue.front() << '\n';
        queue.pop();
    }
}
