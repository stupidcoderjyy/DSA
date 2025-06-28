//
// Created by JYY on 25-6-28.
//

//
// Created by JYY on 25-6-26.
//
#include <vector>
#include <iostream>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
    int l = 0, r = 0, sum = 0, minLen = INT_MAX;
    while (true) {
        while (true) {
            if (r == nums.size()) {
                return minLen == INT_MAX ? 0 : minLen;
            }
            sum += nums[r++];
            if (sum >= target) {
                break;
            }
        }
        while (true) {
            sum -= nums[l++];
            if (sum < target) {
                minLen = min(minLen, r - (l - 1));
                break;
            }
        }
    }
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/minimum-size-subarray-sum/
int main() {
    vector<int> vec = {6,7,8};
    test(minSubArrayLen(1, vec));
}