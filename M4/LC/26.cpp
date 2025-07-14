//
// Created by PC on 25-7-14.
//

#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int calc(char op, int n1, int n2) {
    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        default:
            return 0;
    }
}

int evalRPN(const vector<string>& tokens) {
    stack<int> nums;
    for (auto& s : tokens) {
        if (!isdigit(s[0]) && s.length() == 1) {
            int n2 = nums.top();
            nums.pop();
            int n1 = nums.top();
            nums.pop();
            nums.push(calc(s[0], n1, n2));
        } else {
            nums.push(stoi(s));
        }
    }
    return nums.top();
}

//https://leetcode.cn/problems/evaluate-reverse-polish-notation/
int main() {
    cout << evalRPN({"2","1","+","3","*"}) << endl;
    cout << evalRPN({"4","13","5","/","+"}) << endl;
    cout << evalRPN({"10","6","9","3","+","-11","*","/","*","17","+","5","+"}) << endl;
}