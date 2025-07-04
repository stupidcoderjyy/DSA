//
// Created by PC on 25-7-1.
//

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-1), next() {}
    ListNode(int x) : val(x), next() {}
};

void insertNode(ListNode* p, ListNode* a) {
    a->next = p->next;
    p->next = a;
}

ListNode *buildList(const vector<int> &vec) {
    ListNode *p = nullptr, *h = nullptr;
    for (auto i: vec) {
        if (p) {
            insertNode(p, new ListNode(i));
            p = p->next;
        } else {
            p = new ListNode(i);
            p->next = p;
            h = p;
        }
    }
    return h;
}

void printList(ListNode* head) {
    auto *node = head;
    if (node) {
        do {
            cout << node->val << " ";
            node = node->next;
        } while (node != head);
    }
    cout << "$" << endl;
}

ListNode *findTail(ListNode* h) {
    ListNode *p = h;
    while (p->next != h) {
        p = p->next;
    }
    return p;
}

ListNode* rg98(ListNode* ha, ListNode* hb) {
    auto *ta = findTail(ha), *tb = findTail(hb);
    ta->next = hb;
    tb->next = ha;
    return ha;
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* ha = buildList({1,2,3});
    auto* hb= buildList({4,5,6});
    printList(rg98(ha, hb));
    ha = buildList({1});
    hb= buildList({4});
    printList(rg98(ha, hb));
}