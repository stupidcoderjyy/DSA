//
// Created by JYY on 25-6-26.
//
#include <vector>
#include <iostream>

using namespace std;

void moveZeroes(vector<int> &nums) {
    int i = 0, s = 0;
    while (i < nums.size()) {
        if (nums[i] == 0) {
            i++;
            continue;
        }
        nums[s++] = nums[i++];
    }
    while (s < nums.size()) {
        nums[s++] = 0;
    }
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/backspace-string-compare/
int main() {
    vector<int> vec = {0, 1, 0, 3, 12};
    moveZeroes(vec);
    vec = {};
    moveZeroes(vec);
}