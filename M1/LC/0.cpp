//
// Created by JYY on 25-6-26.
//

#include <vector>
#include <iostream>

//https://leetcode.cn/problems/binary-search/


using namespace std;

int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (target < nums[m]) {
            r = m - 1;
        } else if (target > nums[m]) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return -1;
}

int main() {
    vector<int> vec{-1, 0, 3, 5, 9, 12};
    cout << search(vec, 9) << endl;
    cout << search(vec, 2) << endl;
}