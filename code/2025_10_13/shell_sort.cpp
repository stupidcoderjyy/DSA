//
// Created by PC on 2025/10/14.
//

#include <iostream>
#include <vector>

using std::vector;

//不稳定
//时间复杂度：O(n^(1.3~2)) 空间复杂度O(1)
void ShellSort(vector<int>& vec) {
    int interval = static_cast<int>(vec.size());
    while (interval > 1) {
        interval /= 2;
        //将整个数组分成interval个子序列
        for (int i = 0; i < interval; ++i) {
            //对子序列进行插入排序
            for (int j = i + interval; j < vec.size(); j += interval) {
                int num = vec[j], k = j - interval;
                while (k >= 0 && vec[k] > num) {
                    vec[k + interval] = vec[k];
                    k -= interval;
                }
                vec[k + interval] = num;
            }
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
        ShellSort(vec);
        for (const int& num : vec) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}