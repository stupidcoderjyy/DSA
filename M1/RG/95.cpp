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

void rg95(ListNode* ha, ListNode* hb) {
    ListNode header;
    header.next = ha;
    ListNode *na = ha, *nb = hb, *s = &header;
    while (true) {
        if (!na || !nb) {
            break;
        }
        if (na->val > nb->val) {
            nb = nb->next;
        } else if (na->val < nb->val) {
            na = na->next;
        } else {
            s->next->val = na->val;
            s = s->next;
            na = na->next;
            nb = nb->next;
        }
    }
    auto *nd = s->next;
    while (nd) {
        auto* sn = nd->next;
        delete nd;
        nd = sn;
    }
    s->next = nullptr;
    nd = hb;
    while (nd) {
        auto* sn = nd->next;
        delete nd;
        nd = sn;
    }
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* ha = buildList({1,2,5,7,9});
    auto* hb = buildList({2,4,5,6});
    rg95(ha, hb);
    printList(ha);
    ha = buildList({1,2,4,5});
    hb = buildList({1,2,3,4,5,6,7});
    rg95(ha, hb);
    printList(ha);
}