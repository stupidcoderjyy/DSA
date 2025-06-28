//
// Created by JYY on 25-6-28.
//

//
// Created by JYY on 25-6-26.
//
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool pickFruit(unordered_map<int,int> &bk, int fruit) {
    if (bk.size() < 2 || bk.find(fruit) != bk.end()) {
        bk[fruit]++;
        return true;
    }
    return false;
}

void removeFruit(unordered_map<int,int> &bk, int fruit) {
    if (bk.find(fruit) != bk.end()) {
        if (--bk[fruit] == 0) {
            bk.erase(fruit);
        }
    }
}

int totalSize(unordered_map<int,int> &bk) {
    int total = 0;
    for (auto &[f, n] : bk) {
        total += n;
    }
    return total;
}

int totalFruit(vector<int> &fruits) {
    int l = 0, r = 0;
    unordered_map<int,int> bk;
    bk.reserve(2);
    int res = 0;
    while (true) {
        while (true) {
            if (r == fruits.size()) {
                return max(res, totalSize(bk));
            }
            if (pickFruit(bk, fruits[r])) {
                r++;
            } else {
                break;
            }
        }
        res = max(res, totalSize(bk));
        while (true) {
            if (bk.size() < 2) {
                pickFruit(bk, fruits[r]);
                r++;
                break;
            }
            removeFruit(bk, fruits[l++]);
        }
    }
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/fruit-into-baskets/
int main() {
    vector vec = {1,2,1};
    test(totalFruit(vec));
    vec = {0,1,2,2};
    test(totalFruit(vec));
    vec = {1,2,3,2,2};
    test(totalFruit(vec));
    vec = {3,3,3,1,2,1,1,2,3,3,4};
    test(totalFruit(vec));
    vec = {0,1,2,3};
    test(totalFruit(vec));
    vec = {0};
    test(totalFruit(vec));
}