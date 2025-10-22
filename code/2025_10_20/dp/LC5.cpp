//
// Created by PC on 2025/10/21.
//
#include <cstring>
#include <iostream>
#include <string>

using std::string;

//时间复杂度O(N^2) 空间复杂度O(N^2)
string Solve1(const string &s) {
    //dp[i][j] [i,j]区间是否为回文串
    bool dp[s.length()][s.length()];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < s.length(); ++i) {
        dp[i][i] = true;
    }
    int start = 0, max_len = 1;
    for (int len = 2; len <= s.length(); ++len) {
        for (int i = 0; i + len <= s.length(); ++i) {
            int j = i + len - 1;
            if (s[i] != s[j]) {
                continue;
            }
            dp[i][j] = len == 2 ? true : dp[i + 1][j - 1];
            if (dp[i][j] && len > max_len) {
                max_len = len;
                start = i;
            }
        }
    }
    return s.substr(start, max_len);
}

int MaxLenFromCenter(const string& s, int cl, int cr) {
    while (cl >= 0 && cr < s.length() && s[cl] == s[cr]) {
        cl--;
        cr++;
    }
    return cr - cl - 1;
}

//时间复杂度O(N^2) 空间复杂度O(1)
string Solve2(const string& s) {
    //枚举所有中心
    int start = 0, max_len = 1;
    for (int i = 0; i < s.length(); ++i) {
        int len1 = MaxLenFromCenter(s, i, i);
        int len2 = MaxLenFromCenter(s, i, i + 1);
        int len = std::max(len1, len2);
        if (len > max_len) {
            max_len = len;
            start = i - (len - 1) / 2;
        }
    }
    return s.substr(start, max_len);
}

//时间复杂度O(N^2) 空间复杂度O(N^2)
string longestPalindrome(const string& s) {
    return Solve1(s);
}

int main() {
    std::cout << longestPalindrome("aba") << std::endl;
    std::cout << longestPalindrome("abcba") << std::endl;
    std::cout << longestPalindrome("abcbxa") << std::endl;
    std::cout << longestPalindrome("babab") << std::endl;
    std::cout << longestPalindrome("babad") << std::endl;
    std::cout << longestPalindrome("cbbd") << std::endl;
    std::cout << longestPalindrome("a") << std::endl;
    std::cout << longestPalindrome("aa") << std::endl;
    std::cout << longestPalindrome("aaa") << std::endl;
    std::cout << longestPalindrome("ababbaabb") << std::endl;
    std::cout << longestPalindrome("bababbabbabab") << std::endl;
}