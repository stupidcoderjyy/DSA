//
// Created by PC on 2025/10/23.
//

#include <algorithm>
#include <iostream>
#include <vector>

typedef std::vector<int>::iterator It;

void Sort(const It& begin, const It& end) {
     std::sort(begin, end);
}

int main() {
     std::vector vec{1, 3, 5, 4 ,1};
     Sort(vec.begin(), vec.end());
     for (auto it = vec.begin(); it != vec.end(); ++it) {
          std::cout << *it << " ";
     }
     std::cout << std::endl;

     auto begin = vec.begin();
     vec.insert(vec.begin(), 0);
     //迭代器失效
     std::cout << *begin << std::endl;
}
