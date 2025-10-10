//
// Created by PC on 2025/10/9.
//

#include <stack>
#include <iostream>

using std::stack;

class MyQueue {
public:
    MyQueue() = default;

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        int val = peek();
        st2.pop();
        return val;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
private:
    stack<int> st1, st2;
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << q.peek() << std::endl;
    std::cout << q.pop() << std::endl;
    q.push(4);
    q.push(5);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
}
