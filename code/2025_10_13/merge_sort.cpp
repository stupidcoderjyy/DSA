//
// Created by PC on 2025/10/14.
//

#include <iostream>
#include <vector>

using std::vector;

void merge_sort(vector<int>& vec, int l, int r);
void merge(vector<int>& vec, int m, int l, int r);

//稳定
//时间复杂度：O(NlogN)  空间复杂度O(N)
void MergeSort(vector<int>& vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

void merge_sort(vector<int> &vec, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + ((r - l) >> 1);
    merge_sort(vec, l, m);
    merge_sort(vec, m + 1, r);
    //合并两个有序数组
    merge(vec, m, l, r);
}

void merge(vector<int> &vec, int m, int l, int r) {
    int i = l, j = m + 1, k = 0;
    vector<int> temp(r - l + 1);
    while (i <= m && j <= r) {
        //这里采用<=保证稳定性
        temp[k++] = vec[i] <= vec[j] ? vec[i++] : vec[j++];
    }
    while (i <= m) {
        temp[k++] = vec[i++];
    }
    while (j <= r) {
        temp[k++] = vec[j++];
    }
    std::copy(temp.begin(), temp.end(), vec.begin() + l);
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
        MergeSort(vec);
        for (const int& num : vec) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}
