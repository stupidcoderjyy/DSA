//
// Created by PC on 2025/10/8.
//

#include <iostream>
#include <stack>
#include <string>

using std::string;

string removeKdigits(string num, int k) {
    string result;
    auto it = num.begin();
    //构建单调栈，删掉递减的部分
    while (it != num.end() && k > 0) {
        if (*it == '0' && result.empty()) {
            ++it;
        } else if (!result.empty() && *it < result.back()) {
            --k;
            result.pop_back();
        } else {
            result.push_back(*it++);
        }
    }
    //继续删除
    while (k > 0 && !result.empty()) {
        result.pop_back();
        --k;
    }
    //加入剩余字符
    while (it != num.end()) {
        auto ch = *it++;
        if (!result.empty() || ch != '0') {
            result.push_back(ch);
        }
    }
    return result.empty() ? "0" : result;
}

int main() {
    while (true) {
        int k;
        std::cin >> k;
        if (k == 0) {
            break;
        }
        string s;
        std::cin >> s;
        std::cout << removeKdigits(s, k) << std::endl;
    }
}