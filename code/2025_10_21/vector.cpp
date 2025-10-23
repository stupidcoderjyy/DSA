//
// Created by PC on 2025/10/23.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    for (int i = 0; i < 20; ++i) {
        std::cout << vec.size() << " " << vec.capacity() << '\n';
        vec.push_back(i);
    }
    std::cout << vec[0] << " " << vec[vec.size() - 1] << std::endl;
}
