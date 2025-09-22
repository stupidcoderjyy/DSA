//
// Created by PC on 25-7-14.
//

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    int* data;
    int len;
    int front, rear;
    bool isEmpty;
public:
    explicit Queue(int len): len(len), front(0), rear(0), isEmpty(true) {
        data = new int[len];
    }

    ~Queue() {
        delete data;
    }

    bool empty() const {
        return front == rear && isEmpty;
    }

    bool full() const {
        return front == rear && !isEmpty;
    }

    void push(int val) {
        if (full()) {
            return;
        }
        data[front++] = val;
        if (front == len) {
            front = 0;
        }
        if (isEmpty) {
            isEmpty = false;
        }
    }

    int pop() {
        if (empty()) {
            return -1;
        }
        int val = data[rear++];
        if (rear == len) {
            rear = 0;
        }
        if (front == rear) {
            isEmpty = true;
        }
        return val;
    }
};

int main() {
    Queue s(5);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    cout << s.full() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.push(16);
    s.push(17);
    s.push(18);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.push(19);
    s.push(20);
    while (!s.empty()) {
        cout << s.pop() << endl;
    }
}