//
// Created by PC on 2025/10/5.
//
#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::cin;


int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int base = 0, gain = 0, len = customers.size();
    //统计不使用技能的满意人数
    for (int i = 0; i < len; i++) {
        if (!grumpy[i]) {
            base += customers[i];
        }
    }
    int max_gain = 0;
    //统计使用技能后的最大额外满意人数
    for (int l = 0, r = 0; r < len; l++) {
        //从l开始使用技能的额外满意人数
        for (int r_max = std::min(l + minutes, len); r < r_max; r++) {
            if (grumpy[r]) {
                gain += customers[r];
            }
        }
        max_gain = std::max(max_gain,  gain);
        //移动区间
        if (grumpy[l]) {
            gain -= customers[l];
        }
    }
    return base + max_gain;
}

int main() {
    int len;
    cin >> len;
    vector<int> customers(len);
    for (int i = 0; i < len; i++) {
        cin >> customers[i];
    }
    vector<int> grumpy(len);
    for (int i = 0; i < len; i++) {
        cin >> grumpy[i];
    }
    int minutes;
    cin >> minutes;
    std::cout << maxSatisfied(customers, grumpy, minutes) << std::endl;
}