//
// Created by PC on 25-7-14.
//

using namespace std;

#include <queue>
#include <iostream>

class MyStack {
private:
    queue<int> q;
    int size;
public:
    MyStack() {
        size = 0;
    }

    void push(int x) {
        q.push(x);
        for (int i = 0; i < size; ++i) {
            q.push(q.front());
            q.pop();
        }
        size++;
    }

    int pop() {
        int val = q.front();
        q.pop();
        size--;
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

//https://leetcode.cn/problems/implement-stack-using-queues/description/
int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    stack.push(4);
    stack.push(5);
    stack.push(6);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.empty() << endl;
}