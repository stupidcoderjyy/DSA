//
// Created by PC on 25-7-14.
//

#include <stack>
#include <string>
#include <iostream>

using namespace std;

string removeDuplicates(string s) {
    stack<char> stack;
    for (int i = 0; i < s.length(); ++i) {
        if (stack.empty() || stack.top() != s[i]) {
            stack.push(s[i]);
        } else {
            stack.pop();
        }
    }
    auto len = stack.size();
    if (len == 0) {
        return "";
    }
    char ch[len];
    for (auto i = len - 1; i < len; --i) {
        ch[i] = stack.top();
        stack.pop();
    }
    return {ch, len};
}

//https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
int main() {
    cout << removeDuplicates("a") << endl;
    cout << removeDuplicates("abcd") << endl;
    cout << removeDuplicates("abccddbca") << endl;
    cout << removeDuplicates("abba") << endl;
    cout << removeDuplicates("aaaaaaaa") << endl;
}