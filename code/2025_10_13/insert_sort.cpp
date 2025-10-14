//
// Created by PC on 2025/10/14.
//

#include <iostream>
#include <vector>

using std::vector;

//稳定 相同的元素不会向右移动, 故相对顺序不变
//最好|最坏|平均时间复杂度：O(n)|O(n^2)|O(n^2)  空间复杂度O(1)
void InsertSort(vector<int>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        //空出第1位
        int num = vec[i], j = i - 1;
        //逐个右移
        while (j >= 0 && vec[j] > num) {
            vec[j + 1] = vec[j];
            --j;
        }
        //填入正确空位
        vec[j + 1] = num;
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
        InsertSort(vec);
        for (const int& num : vec) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}