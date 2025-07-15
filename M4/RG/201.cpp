//
// Created by PC on 25-7-14.
//

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    int* data;
    int len;
    int top1, top2;
public:
    explicit Stack(int len): len(len), top1(-1), top2(len) {
        data = new int[len];
    }

    ~Stack() {
        delete data;
    }

    bool empty(bool left) const {
        return left ? top1 == -1 : top2 == len;
    }

    bool full() const {
        return top1 == top2 - 1;
    }

    void push(bool left, int val) {
        if (full()) {
            return;
        }
        if (left) {
            data[++top1] = val;
        } else {
            data[--top2] = val;
        }
    }

    int pop(bool left) {
        if (empty(left)) {
            return -1;
        }
        return left ? data[top1--] : data[top2++];
    }
};

int main() {
    Stack s(5);
    s.push(true, 10);
    s.push(true, 11);
    s.push(true, 12);
    s.push(true, 13);
    s.push(true, 14);
    cout << s.full() << endl;
    cout << s.pop(true) << endl;
    cout << s.pop(true) << endl;
    cout << s.empty(true) << endl;
    cout << s.pop(true) << endl;
    cout << s.empty(true) << endl;
    s.push(false, 13);
    s.push(false, 14);
    s.push(false, 15);
    cout << s.full() << endl;
    cout << s.pop(false) << endl;
    cout << s.pop(false) << endl;
}