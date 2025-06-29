//
// Created by JYY on 25-6-29.
//

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int calc(char op, int v1, int v2) {
    switch (op) {
        case '+':
            return v1 + v2;
        case '-':
            return v1 - v2;
        case '*':
            return v1 * v2;
        case '/':
            return v1 / v2;
        default:
            return 0;
    }
}

int calcPostfix(const string& s) {
    stack<char> op;
    stack<int> num;
    for (auto &c : s) {
        switch (c) {
            case '+':
            case '-':
            case '*':
            case '/': {
                int v2 = num.top();
                num.pop();
                int v1 = num.top();
                num.pop();
                num.push(calc(c, v1, v2));
                break;
            }
            default:
                num.push(c - '0');
                break;
        }
    }
    return num.top();
}

int main() {
    string s;
    while (true) {
        cin >> s;
        if (s == "$") {
            break;
        }
        cout << calcPostfix(s) << endl;
    }
}