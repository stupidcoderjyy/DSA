//
// Created by PC on 25-7-14.
//

#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool match(char c1, char c2) {
    switch (c1) {
        case '(':
            return c2 == ')';
        case '[':
            return c2 == ']';
        case '{':
            return c2 == '}';
        default:
            return false;
    }
}

bool isValid(string s) {
    int i = 0;
    stack<char> stack;
    while (i < s.length()) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                stack.push(s[i]);
                break;
            default:
                if (stack.empty() || !match(stack.top(), s[i])) {
                    return false;
                }
                stack.pop();
                break;
        }
        i++;
    }
    return stack.empty();
}

//https://leetcode.cn/problems/valid-parentheses/
int main() {
    cout << isValid("(((") << endl;
    cout << isValid("([]}") << endl;
    cout << isValid("()]") << endl;
    cout << isValid("(()[]{})") << endl;
}