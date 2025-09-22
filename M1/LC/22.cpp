//
// Created by PC on 25-7-14.
//

using namespace std;

#include <stack>
#include <iostream>

class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() {
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int val = peek();
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

//https://leetcode.cn/problems/implement-queue-using-stacks/description/
int main() {
    MyQueue queue;
    queue.push(1);
    cout << queue.pop() << endl;
    queue.push(2);
    queue.push(3);
    cout << queue.pop() << endl;
    queue.push(4);
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.empty() << endl;
}