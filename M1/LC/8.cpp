//
// Created by JYY on 25-6-26.
//
#include <vector>
#include <iostream>

using namespace std;

void handleString(string& s, int& i) {
    int bc = 0;
    while (i >= 0) {
        if (s[i] == '#') {
            bc++;
            i--;
        } else if (bc == 0) {
            break;
        } else {
            bc--;
            i--;
        }
    }
}

bool backspaceCompare(string s, string t) {
    int i1 = s.length() - 1, i2 = t.length() - 1;
    while (true) {
        handleString(s, i1);
        handleString(t, i2);
        if (i1 < 0 || i2 < 0) {
            return i1 < 0 && i2 < 0;
        }
        if (s[i1] == t[i2]) {
            i1--;
            i2--;
        } else {
            return false;
        }
    }
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/backspace-string-compare/
int main() {
    test(backspaceCompare("ba#aa##", "baaa###"));
    test(backspaceCompare("ab#c", "ad#c"));
    test(backspaceCompare("a#c", "b"));
}