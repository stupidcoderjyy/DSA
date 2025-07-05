//
// Created by PC on 25-7-1.
//

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-1), next(nullptr) {}
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

void printList(ListNode* head) {
    auto *node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << '$' << endl;
}

void insertNode(ListNode* p, ListNode* a) {
    a->next = p->next;
    p->next = a;
}

void removeNode(ListNode* p, ListNode* a) {
    p->next = a->next;
}

ListNode* rg100(ListNode *head, int k) {
    auto *n = head;
    int len = 1;
    while (n->next) {
        n = n->next;
        len++;
    }
    n->next = head;
    for (int i = 0; i < len - k; ++i) {
        n = n->next;
    }
    head = n->next;
    n->next = nullptr;
    return head;
}

int main() {
    auto *h = buildList({1,2,3,4,5});
    printList(rg100(h, 1));
    h = buildList({1,2});
    printList(rg100(h, 1));
}