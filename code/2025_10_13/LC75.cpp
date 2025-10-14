//
// Created by PC on 2025/10/14.
//

#include <vector>

using std::vector;

int partition(vector<int>& vec, int l, int r) {
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

void quick_sort(vector<int>& vec, int l, int r) {
    if (l >= r) {
        return;
    }
    int pivot = partition(vec, l, r);
    quick_sort(vec, l, pivot - 1);
    quick_sort(vec, pivot + 1, r);
}

void sortColors(vector<int>& vec) {
    quick_sort(vec, 0, vec.size() - 1);
}
