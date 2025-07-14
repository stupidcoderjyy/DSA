//
// Created by JYY on 25-6-29.
//

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, char> pairs{
        {'[', ']'},
        {'{', '}'},
        {'(', ')'}
};

bool match(const string& s) {
    stack<char> st;
    for (auto &c: s) {
        if (pairs.contains(c)) {
            st.push(c);
        } else {
            if (st.empty() || pairs[st.top()] != c) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    while (true) {
        cin >> s;
        if (s == "$") {
            break;
        }
        cout << match(s) << endl;
    }
}