#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int count = 0;

void CountPairs(vector<int> &vec, int m, int l, int r) {
    int i = l, j = m + 1;
    //统计翻转对 (x,y)∈[l, m]x[m+1,r]
    //经过归并过程，最终得到所有翻转对
    while (i <= m && j <= r) {
        if (static_cast<long long>(vec[i]) > 2LL * vec[j]) {
            count += m - i + 1;
            j++;
        } else {
            i++;
        }
    }
}

void Merge(vector<int> &vec, int m, int l, int r) {
    CountPairs(vec, m, l, r);
    int i = l, j = m + 1, k = 0;
    vector<int> temp(r - l + 1);
    while (i <= m && j <= r) {
        //这里采用<=保证稳定性
        temp[k++] = vec[i] <= vec[j] ? vec[i++] : vec[j++];
    }
    if (i <= m) {
        std::copy(vec.begin() + i, vec.begin() + m + 1, temp.begin() + k);
    }
    if (j <= r) {
        std::copy(vec.begin() + j, vec.begin() + r + 1, temp.begin() + k);
    }
    std::copy(temp.begin(), temp.end(), vec.begin() + l);
}

void MergeSort(vector<int> &vec, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + ((r - l) >> 1);
    MergeSort(vec, l, m);
    MergeSort(vec, m + 1, r);
    //合并两个有序数组
    Merge(vec, m, l, r);
}

int reversePairs(vector<int>& nums) {
    count = 0;
    MergeSort(nums, 0, nums.size() - 1);
    return count;
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
        std::cout << reversePairs(vec) << std::endl;
    }
    return 0;
}