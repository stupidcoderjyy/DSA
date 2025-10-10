#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using std::string;

//时间复杂度：O(n) 空间复杂度：O(1)
int lengthOfLongestSubstring(string s) {
    bool bits[128] = {};
    int l = 0, r = 0, max_len = 0;
    while (r < s.size()) {
        //找到以l为首元素的最长不重复区间
        while (r < s.size() && !bits[s[r]]) {
            bits[s[r++]] = true;
        }
        max_len = std::max(max_len, r - l);
        if (r == s.size()) {
            break;
        }
        //右移l，直到删除重复元素
        while (bits[s[r]]) {
            bits[s[l++]] = false;
        }
    }
    return max_len;
}

int main() {
    while (true) {
        string s;
        std::getline(std::cin, s);
        if (s == "$") {
            break;
        }
        std::cout << lengthOfLongestSubstring(s) << std::endl;
    }
}