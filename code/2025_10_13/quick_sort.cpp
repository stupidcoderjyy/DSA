//
// Created by PC on 2025/10/14.
//

#include <iostream>
#include <vector>

using std::vector;

//不稳定
//最好|最坏|平均时间复杂度：O(N)|O(N^2)|O(NlogN)  最好|最坏|平均空间复杂度O(logN)|O(N)|O(logN)
int Partition(vector<int>& vec, int l, int r) {
    int pivot_num = vec[l];
    //以pivot_num为界将vec分成2组
    while (l < r) {
        //空位为l
        while (l < r && vec[r] >= pivot_num) {
            --r;
        }
        //填入空位
        if (l < r) {
            vec[l] = vec[r];
        }
        //空位在r
        while (l < r && vec[l] <= pivot_num) {
            ++l;
        }
        //填入空位
        if (l < r) {
            vec[r] = vec[l];
        }
    }
    vec[l] = pivot_num;
    return l;
}

void QuickSort(vector<int>& vec, int l, int r) {
    if (l >= r) {
        return;
    }
    int pivot = Partition(vec, l, r);
    QuickSort(vec, l, pivot - 1);
    QuickSort(vec, pivot + 1, r);
}

void QuickSort(vector<int>& vec) {
    QuickSort(vec, 0, vec.size() - 1);
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
        QuickSort(vec);
        for (const int& num : vec) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}