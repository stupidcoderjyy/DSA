//
// Created by JYY on 25-6-29.
//

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, int> priority{
        {'+', 0},
        {'-', 1},
        {'*', 2},
        {'/', 3}
};

string toPostfix(const string& s) {
    stack<char> op;
    char res[s.size()];
    size_t i = 0;
    for (auto &c : s) {
        switch (c) {
            case '(':
                op.push(c);
                break;
            case ')':
                while (op.top() != '(') {
                    res[i++] = op.top();
                    op.pop();
                }
                op.pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (op.empty() || op.top() == '(' || priority[c] > priority[op.top()]) {
                    op.push(c);
                } else {
                    do {
                        res[i++] = op.top();
                        op.pop();
                    } while (!op.empty() && op.top() != '(' && priority[op.top()] >= priority[c]);
                    op.push(c);
                }
                break;
            default:
                res[i++] = c;
                break;
        }
    }
    while (!op.empty()) {
        res[i++] = op.top();
        op.pop();
    }
    return {res, i};
}

int main() {
    string s;
    while (true) {
        cin >> s;
        if (s == "$") {
            break;
        }
        cout << toPostfix(s) << endl;
    }
}