//
// Created by PC on 25-7-1.
//

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(-1), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
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

void printList(ListNode *head) {
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
    ListNode *b = head;
    ListNode *c = head->next;
    b->next = nullptr;
    while (true) {
        if (!c) {
            return b;
        }
        auto *cn = c->next;
        c->next = b;
        b = c;
        c = cn;
    }
}

int rg102(ListNode *h) {
    ListNode *f = h, *s = h, *h2;
    while (true) {
        f = f->next->next;
        if (!f) {
            h2 = s->next;
            s->next = nullptr;
            break;
        }
        s = s->next;
    }
    int res = 0;
    auto *h1 = h;
    h2 = reverseList(h2);
    while (h1) {
        res = max(res, h1->val + h2->val);
        h1 = h1->next;
        h2 = h2->next;
    }
    return res;
}

ListNode* findMid(ListNode *h) {
    auto *f = h, *s = h;
    while (f && f->next) {
        f = f->next->next;
        s = s->next;
    }
    return s;
}

int main() {
    auto *h = buildList({1, 4, 2, 6, 3, 3});
    cout << rg102(h) << endl;
    h = buildList({1, 2});
    cout << rg102(h) << endl;
    h = buildList({2, 2, 4, 3});
    cout << rg102(h) << endl;
}
