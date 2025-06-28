//
// Created by JYY on 25-6-28.
//
#include <vector>
#include <iostream>

using namespace std;

vector<int> sortedSquares(vector<int> &nums) {
    size_t l = 0, r = nums.size() - 1;
    vector<int> res;
    res.resize(nums.size());
    auto i = r;
    while (true) {
        int nl = nums[l], nr = nums[r];
        if (l == r) {
            res[0] = nl * nl;
            return res;
        }
        if (abs(nl) > abs(nr)) {
            res[i--] = nl * nl;
            l++;
        } else {
            res[i--] = nr * nr;
            r--;
        }
    }
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/minimum-window-substring/description/
int main() {
    vector vec = {-4, -1, 0, 1,2,3};
    sortedSquares(vec);
    vec = {0};
    sortedSquares(vec);
    vec = {0, 1, 2, 3};
    sortedSquares(vec);
    vec = {-4, -1};
    sortedSquares(vec);
}