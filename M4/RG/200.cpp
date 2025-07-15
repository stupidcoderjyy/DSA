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
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildList(const vector<int> &vec) {
    ListNode header;
    ListNode *parent = &header;
    for (auto i: vec) {
        parent->next = new ListNode(i);
        parent = parent->next;
    }
    return header.next;
}

void removeNode(ListNode* p, ListNode* a) {
    p->next = a->next;
    delete a;
}

bool rg200(ListNode* head) {
    auto* n = head;
    int len = 0;
    while (n) {
        len++;
        n = n->next;
    }
    int half = len / 2;
    n = head;
    stack<int> stack;
    for (int i = 0; i < half; ++i) {
        stack.push(n->val);
        n = n->next;
    }
    if ((len & 1) == 1) {
        n = n->next;
    }
    while (!stack.empty()) {
        if (stack.top() != n->val) {
            return false;
        }
        stack.pop();
        n = n->next;
    }
    return true;
}


int main() {
    auto* head = buildList({1});
    cout << rg200(head) << endl;
    head = buildList({1,3,1});
    cout << rg200(head) << endl;
    head = buildList({1,3,3});
    cout << rg200(head) << endl;
    head = buildList({1,2,2,1});
    cout << rg200(head) << endl;
    head = buildList({1,2,2,2});
    cout << rg200(head) << endl;
}