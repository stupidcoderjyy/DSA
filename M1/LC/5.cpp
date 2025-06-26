//
// Created by JYY on 25-6-26.
//
#include <vector>
#include <iostream>

using namespace std;

int removeElement(vector<int> &nums, int val) {
    int i = 0, s = 0;
    while(i < nums.size()) {
        if (nums[i] == val) {
            i++;
            continue;
        }
        nums[s++] = nums[i++];
    }
    return s;
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/remove-element/description/
int main() {
    vector<int> vec = {0, 1, 2, 2, 3, 0, 4, 2};
    test(removeElement(vec, 2));
}