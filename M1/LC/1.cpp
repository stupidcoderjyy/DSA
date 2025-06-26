//
// Created by JYY on 25-6-26.
//

#include <vector>
#include <iostream>

//https://leetcode.cn/problems/search-insert-position/description/


using namespace std;

int searchInsert(vector<int> &nums, int target) {
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
    return l;
}

int main() {
    vector<int> vec{1, 3, 5, 6};
    cout << searchInsert(vec, 5) << endl;
    cout << searchInsert(vec, 2) << endl;
    cout << searchInsert(vec, 7) << endl;
    cout << searchInsert(vec, 0) << endl;
}