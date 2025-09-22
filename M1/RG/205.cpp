//
// Created by PC on 25-7-1.
//

#include <vector>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Queue {
private:
    ListNode* front, *rear;
public:
    Queue() {
        front = new ListNode;
        rear = front;
        front->next = front;
    }

    bool empty() const {
        return rear == front;
    }

    void push(int x) {
        if (rear->next == front) {
            auto* node = new ListNode;
            node->next = rear->next;
            rear->next = node;
        }
        rear->val = x;
        rear = rear->next;
    }

    int pop() {
        if (empty()) {
            return -1;
        }
        int val = front->val;
        front = front->next;
        return val;
    }
};

int main() {
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    queue.push(4);
    queue.push(5);
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.empty() << endl;
}