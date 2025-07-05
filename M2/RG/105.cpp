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

void removeNode(ListNode* p, ListNode* a) {
    p->next = a->next;
    delete a;
}

ListNode* rg105(ListNode *h) {
    int max = 0;
    auto *n = h->next;
    while (n) {
        max = std::max(max, abs(n->val));
        n = n->next;
    }
    bool exist[max + 1];
    memset(exist, false, sizeof(bool) * (max + 1));
    auto *p = h;
    while (true) {
        auto *a = p->next;
        if (!a) {
            return h;
        }
        int i = abs(a->val);
        if (exist[i]) {
            removeNode(p, a);
        } else {
            exist[i] = true;
            p = p->next;
        }
    }
}

int main() {
    auto *h = buildList({0,-1,2,-2,3,-3,-5,5,5});
    printList(rg105(h));
    h = buildList({1});
    printList(rg105(h));
    h = buildList({21,-15,15,-7,15});
    printList(rg105(h));
}