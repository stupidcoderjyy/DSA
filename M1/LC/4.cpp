//
// Created by JYY on 25-6-26.
//
#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectSquare(int num) {
    int l = 1, r = 46340;
    while (l <= r) {
        int m = (l + r) / 2, m2 = m * m;
        if (num > m2) {
            l = m + 1;
        } else if (num < m2) {
            r = m - 1;
        } else {
            return true;
        }
    }
    return false;
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/valid-perfect-square/
int main() {
    test(isPerfectSquare(INT_MAX));
    test(isPerfectSquare(46340 * 46340));
    test(isPerfectSquare(1));
    test(isPerfectSquare(2));
    test(isPerfectSquare(4));
    test(isPerfectSquare(5));
}