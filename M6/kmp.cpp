//
// Created by PC on 25-7-9.
//

#include <string>
#include <iostream>

using namespace std;

void buildNext(const string& ptn, int next[]) {
    next[0] = -1;
    int k = 1;
    while (k < ptn.length()) {
        int c = k - 1;
        while (true) {
            c = next[c];
            if (c < 0 || ptn[k - 1] == ptn[c] && ptn[k] != ptn[c + 1]) {
                break;
            }
        }
        next[k++] = c + 1;
    }
}

int indexOf(const string& s, const string& p) {
    int next[p.length()];
    buildNext(p, next);
    int i = 0, j = 0;
    while (i < s.length() && j < p.length()) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else if (j == 0) {
            i++;
        } else {
            j = next[j];
        }
    }
    return j == p.length();
}

int main() {
    cout << indexOf("abcde", "cde") << endl;
    cout << indexOf("aabaabba", "aabbaa") << endl;
    cout << indexOf("abaabaaabaaaab", "aaaab") << endl;
    cout << indexOf("a", "aaaab") << endl;
}