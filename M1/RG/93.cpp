//
// Created by PC on 25-7-1.
//

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() {
        cout << "x " << val << endl;
    }
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

void printList(ListNode* head) {
    auto *node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << '$' << endl;
}

ListNode* rg93(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    ListNode *s = head, *c = head->next;
    while (true) {
        if (!c) {
            s->next = nullptr;
            return head;
        }
        if (c->val != s->val) {
            s->next = c;
            s = c;
        }
        c = c->next;
    }
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* head = buildList({1,2,2,3,4,4});
    rg93(head);
    printList(head);
    head = buildList({1,1,1});
    rg93(head);
    printList(head);
    head = buildList({1});
    rg93(head);
    printList(head);
}