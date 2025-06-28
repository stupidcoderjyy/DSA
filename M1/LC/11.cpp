//
// Created by JYY on 25-6-28.
//

//
// Created by JYY on 25-6-26.
//
#include <vector>
#include <iostream>

using namespace std;

bool tryPick(int &f1, int &f2, int f) {
    if (f1 == f || f2 == f) {
        return true;
    }
    if (f1 < 0) {
        f1 = f;
        return true;
    }
    if (f2 < 0) {
        f2 = f;
        return true;
    }
    return false;
}

int totalFruit(vector<int> &fruits) {
    int l = 0, r = 0;
    int f1 = -1, f2 = -1;
    int res = 0;
    while (true) {
        while (true) {
            if (r == fruits.size()) {
                return max(res, r - l);
            }
            if (tryPick(f1, f2, fruits[r])) {
                r++;
            } else {
                break;
            }
        }
        res = max(res, r - l);
        f1 = fruits[r];
        f2 = fruits[r - 1];
        l = r - 2;
        while (true) {
            if (tryPick(f1, f2, fruits[l])) {
                l--;
            } else {
                break;
            }
        }
        l++;
        r++;
    }
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/fruit-into-baskets/
int main() {
    vector<int> vec = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    test(totalFruit(vec));
    vec = {1};
    test(totalFruit(vec));
    vec = {1, 1, 1};
    test(totalFruit(vec));
    vec = {1, 2};
    test(totalFruit(vec));
}