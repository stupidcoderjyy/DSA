//
// Created by PC on 25-7-1.
//

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next, *prev;
    ListNode() : val(-1), next(), prev() {}
    ListNode(int x) : val(x), next(), prev() {}
};

void insertNode(ListNode* p, ListNode* a) {
    a->next = p->next;
    p->next->prev = a;
    p->next = a;
    a->prev = p;
}

ListNode *buildList(const vector<int> &vec) {
    ListNode *h = new ListNode;
    h->next = h;
    h->prev = h;
    ListNode *p = h;
    for (auto i: vec) {
        insertNode(p, new ListNode(i));
        p = p->next;
    }
    return h;
}

void printList(ListNode* head) {
    auto *node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << '$' << endl;
}

bool rg97(ListNode* ha) {
    auto *l = ha->prev, *r = ha->next;
    while (true) {
        if (l == r) {
            return true;
        }
        if (l->val != r->val) {
            return false;
        }
        if (r->next == l) {
            return true;
        }
        l = l->prev;
        r = r->next;
    }
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* h = buildList({1,2,3,2,1});
    cout << rg97(h) << endl;
    h = buildList({1,2,2,1});
    cout << rg97(h) << endl;
    h = buildList({1,2,4,1});
    cout << rg97(h) << endl;
    h = buildList({1});
    cout << rg97(h) << endl;
    h = buildList({});
    cout << rg97(h) << endl;
    h = buildList({1,2,3,4,3,3,2,1});
    cout << rg97(h) << endl;
}