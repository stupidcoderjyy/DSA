//
// Created by JYY on 25-6-28.
//
#include <cstring>
#include <iostream>
using namespace std;

string minWindow(string s, string t) {
    int l = 0, r = 0;
    int rl = 0, rr = INT_MAX;
    int supposed[128];
    int actual[128];
    int uc = 0;
    memset(supposed, 0, 128 * sizeof(int));
    memset(actual, 0, 128 * sizeof(int));
    for (auto c : t) {
        if (supposed[c]++ == 0) {
            uc++;
        }
    }
    while (true) {
        while (true) {
            if (r == s.size()) {
                return rr == INT_MAX ? "" : s.substr(rl, rr - rl);
            }
            char c = s[r++];
            if (supposed[c] > 0) {
                if (++actual[c] == supposed[c]) {
                    uc--;
                }
            }
            if (uc == 0) {
                break;
            }
        }
        while (uc == 0) {
            char c = s[l++];
            if (supposed[c] > 0) {
                if (--actual[c] < supposed[c]) {
                    uc++;
                }
            }
        }
        if (rr - rl > r - (l - 1)) {
            rr = r;
            rl = l - 1;
        }
    }
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/fruit-into-baskets/
int main() {
    test(minWindow("ADOBECODEBANC", "ABC"));
    test(minWindow("a", "aa"));
    test(minWindow("abcadawdaaabcaaa", "abcaa"));
}