//
// Created by PC on 2025/10/8.
//

#include <iostream>
#include <stack>
#include <string>

using std::string;
using std::stack;

string removeDuplicates(const string &s) {
    //把字符串本身当成栈
    string result;
    for (auto c : s) {
        if (result.empty() || result.back() != c) {
            result.push_back(c);
        } else {
            result.pop_back();
        }
    }
    return result;
}

int main() {
    while (true) {
        string s;
        std::getline(std::cin, s);
        if (s.empty()) {
            break;
        }
        std::cout << removeDuplicates(s) << std::endl;
    }
}