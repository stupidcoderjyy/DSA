//
// Created by PC on 2025/10/14.
//

#include <iostream>
#include <vector>

using std::vector;

//不稳定
//最好|最坏|平均时间复杂度：O(n^2) 空间复杂度O(1)
void SelectSort(vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        int min_pos = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[min_pos]) {
                min_pos = j;
            }
        }
        if (min_pos != i) {
            std::swap(vec[i], vec[min_pos]);
        }
    }
}

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n < 0) {
            break;
        }
        vector<int> vec(n);
        for (int& num : vec) {
            std::cin >> num;
        }
        SelectSort(vec);
        for (const int& num : vec) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}