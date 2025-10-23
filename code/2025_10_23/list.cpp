//
// Created by PC on 2025/10/23.
//

#include <algorithm>
#include <iostream>
#include <list>

void InsertAndErase(std::list<int>& list, int i, int val) {
    if (i < list.size()) {
        if (i == list.size() - 1) {
            list.push_back(val);
        }
        auto it = list.begin();
        for (int j = 0; j < i; ++j) {
            ++it;
        }
        list.insert(it, val);
    }
    auto it = std::find_if(list.begin(), list.end(), [](int v) {
        return (v & 1) == 0;
    });
    list.erase(it);
}

int main() {
    std::list list{1, 2, 3};
    list.insert(list.begin(), 0);
    list.push_back(4);
    InsertAndErase(list, 1, 5);
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    list.sort();
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    list.reverse();
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
