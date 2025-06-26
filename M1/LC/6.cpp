//
// Created by JYY on 25-6-26.
//
#include <vector>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    int i = 0, s = 0;
    int v;
    while (i < nums.size()) {
        v = nums[i];
        nums[s++] = v;
        i++;
        while (i < nums.size()) {
            if (nums[i] == v) {
                i++;
            } else {
                break;
            }
        }
    }
    return s;
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
int main() {
    vector<int> vec{1, 1, 2};
    test(removeDuplicates(vec));
    vec = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    test(removeDuplicates(vec));
    vec = {};
    test(removeDuplicates(vec));
}