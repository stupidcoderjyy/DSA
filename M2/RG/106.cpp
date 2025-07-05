//
// Created by PC on 25-7-1.
//

#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildList(const vector<int> &vec) {
    auto *header = new ListNode;
    auto *parent = header;
    for (auto i: vec) {
        parent->next = new ListNode(i);
        parent = parent->next;
    }
    return header;
}

void printList(ListNode* head) {
    auto *node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << '$' << endl;
}

ListNode *reverseList(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    ListNode* b = head;
    ListNode* c = head->next;
    b->next = nullptr;
    while (true) {
        if (!c) {
            return b;
        }
        auto* cn = c->next;
        c->next = b;
        b = c;
        c = cn;
    }
}

void insertNode(ListNode* p, ListNode* a) {
    if (a) {
        a->next = p->next;
        p->next = a;
    }
}

int countList(ListNode *h) {
    int len = 0;
    auto *n = h->next;
    while (n) {
        len++;
        n = n->next;
    }
    return len;
}

ListNode* rg106(ListNode *h) {
    int len = countList(h);
    auto *n = h;
    int splitLen = (len & 1) == 0 ? len / 2 : len / 2 + 1;
    for (int i = 0; i < splitLen; ++i) {
        n = n->next;
    }
    auto *h2 = n->next;
    n->next = nullptr;
    h2 = reverseList(h2);
    auto *n1 = h->next, *n2 = h2;
    while (n2) {
        auto *n22 = n2->next;
        insertNode(n1, n2);
        n1 = n2->next;
        n2 = n22;
    }
    return h;
}

int main() {
    auto *h = buildList({1,3,5,6,4,2});
    printList(rg106(h));
    h = buildList({1,3,5,4,2});
    printList(rg106(h));
    h = buildList({1});
    printList(rg106(h));
}