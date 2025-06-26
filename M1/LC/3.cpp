//
// Created by JYY on 25-6-26.
//
#include <iostream>
#include <cmath>

using namespace std;

int mySqrt(int x) {
    if (x >= 2147395600) {
        return 46340;
    }
    int l = 0, r = 46340;
    while (l <= r) {
        int m = (l + r) / 2;
        if (x >= (m + 1) * (m + 1)) {
            l = m + 1;
        } else if (x < m * m) {
            r = m - 1;
        } else {
            return m;
        }
    }
    return -1;
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/sqrtx/description/
int main() {
    test(mySqrt(INT_MAX));
    test(mySqrt(0));
    test(mySqrt(1));
    test(mySqrt(2));
    test(mySqrt(4));
    test(mySqrt(5));
}