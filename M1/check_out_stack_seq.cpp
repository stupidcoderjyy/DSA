//
// Created by JYY on 25-6-30.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool check(int n, const vector<int> &out) {
    stack<int> st;
    int i = 0, j = 0;
    while (true) {
        while (true) {
            if (st.empty() || st.top() < out[j]) {
                st.push(i++);
            } else if (st.top() == out[j]) {
                break;
            } else {
                return false;
            }
        }
        while (true) {
            st.pop();
            j++;
            if (j == n) {
                return true;
            }
            if (st.empty() || st.top() != out[j]) {
                break;
            }
        }
    }
}

int main() {
    cout << check(6, {5,4,3,2,1,0}) << endl;
    cout << check(6, {1,2,0,5,4,3}) << endl;
    cout << check(6, {3,2,4,5,1,0}) << endl;
    cout << check(6, {2,0,1,3,4,5}) << endl;
}