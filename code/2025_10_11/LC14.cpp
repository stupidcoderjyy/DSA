//
// Created by PC on 2025/10/11.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

//时间复杂度: O(mn) m: 列表长度, n:字符串平均长度；空间复杂度O(1)
string longestCommonPrefix(const vector<string>& strs) {
    int i = 0;
    std::stringstream ss;
    while (i < strs[0].length()) {
        char ch = strs[0][i];
        for (int j = 1; j < strs.size(); ++j) {
            if (i == strs[j].length() || strs[j][i] != ch) {
                return ss.str();
            }
        }
        ss << ch;
        i++;
    }
    return ss.str();
}

int main() {
    std::cout << longestCommonPrefix({"a", ""}) << std::endl;
    std::cout << longestCommonPrefix({"", "a"}) << std::endl;
    while (true) {
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        vector<string> vec(n);
        for (auto& s : vec) {
            std::cin >> s;
        }
        std::cout << longestCommonPrefix(vec) << std::endl;
    }
    return 0;
}