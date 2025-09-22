//
// Created by PC on 25-7-1.
//

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val, freq;
    ListNode *next, *prev;
    ListNode() : val(-1), freq(), next(), prev() {}
    ListNode(int x) : val(x), freq(), next(), prev() {}
};

void insertNode(ListNode* p, ListNode* a) {
    a->next = p->next;
    if (p->next) {
        p->next->prev = a;
    }
    p->next = a;
    a->prev = p;
}

void removeNode(ListNode* p, ListNode* a) {
    p->next = a->next;
    if (a->next) {
        a->next->prev = p;
    }
}

ListNode *buildList(const vector<int> &vec) {
    auto *h = new ListNode;
    auto *p = h;
    for (auto i: vec) {
        insertNode(p, new ListNode(i));
        p = p->next;
    }
    return h;
}

void printList(ListNode* head) {
    auto *node = head->next;
    while (node) {
        cout << node->val << "[" << node->freq << "] ";
        node = node->next;
    }
    cout << "$" << endl;
}

bool shouldInsert(ListNode *a, ListNode *b, ListNode *p) {
    if (!b) {
        return a->freq < p->freq;
    }
    return p->freq > a->freq && a->freq <= p->freq;
}

ListNode* rg99(ListNode *h, int x) {
    auto *p = h;
    h->freq = INT_MAX;
    ListNode *a;
    while (true) {
        a = p->next;
        if (!a) {
            return nullptr;
        }
        if (a->val == x) {
            a->freq++;
            removeNode(p, a);
            break;
        }
        p = p->next;
    }
    while (true) {
        if (shouldInsert(a, p->next, p)) {
            insertNode(p, a);
            return a;
        }
        p = p->prev;
    }
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* h = buildList({1,2,3,4,5});
    rg99(h, 1);
    rg99(h, 5);
    rg99(h, 5);
    rg99(h, 4);
    rg99(h, 6);
    rg99(h, 0);
    rg99(h, 3);
    rg99(h, 3);
    printList(h);
    h = buildList({1});
    rg99(h, 1);
    rg99(h, 1);
    printList(h);
}