//
// Created by PC on 25-7-14.
//

#include <deque>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


void rg203(deque<int>& deque) {
    stack<int> stack;
    while (!deque.empty()) {
        stack.push(deque.front());
        deque.pop_front();
    }
    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
}

//https://leetcode.cn/problems/sliding-window-maximum/
int main() {
    deque deque = {1,2,3,4,5};
    rg203(deque);
}