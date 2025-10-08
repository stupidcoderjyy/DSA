//
// Created by PC on 2025/10/8.
//

#include <stack>
#include <string>
using std::stack;
using std::string;

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

bool isValid(const string &s) {
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