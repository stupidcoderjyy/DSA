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

void appendNode(ListNode* p, ListNode* a) {
    p->next = a;
}

ListNode* rg94(ListNode* ha, ListNode* hb) {
    ListNode *na = ha->next, *nb = hb->next;
    ListNode header;
    ListNode *p = &header;
    while (true) {
        if (!na) {
            return header.next;
        }
        while (true) {
            if (!nb) {
                return header.next;
            }
            if (nb->val >= na->val) {
                break;
            }
            nb = nb->next;
        }
        if (nb->val == na->val && (p == &header || p->val != nb->val)) {
            appendNode(p, new ListNode(nb->val));
            p = p->next;
            nb = nb->next;
        }
        na = na->next;
    }
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* ha = buildList({-1,1,2,2,10,11,12,15});
    auto* hb = buildList({-1,2,2,5,6,7,11,14,15});
    printList(rg94(ha, hb));
    ha = buildList({-1,1,1,1,2,2,2,3});
    hb = buildList({-1,1,1,2,2,3});
    printList(rg94(ha, hb));
}