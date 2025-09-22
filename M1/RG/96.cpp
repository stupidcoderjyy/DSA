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

bool rg96(ListNode* ha, ListNode* hb) {
    ListNode *a = ha;
    while (true) {
        if (!a) {
            return false;
        }
        auto *na = a, *nb = hb;
        while (true) {
            if (!nb) {
                return true;
            }
            if (na->val == nb->val) {
                na = na->next;
                nb = nb->next;
            } else {
                a = a->next;
                break;
            }
        }
    }
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* ha = buildList({1,1,2,1,2,3});
    auto* hb = buildList({1,2,3});
    cout << rg96(ha, hb) << endl;
    ha = buildList({1,2,5});
    hb = buildList({1,2,3});
    cout << rg96(ha, hb) << endl;
    ha = buildList({3});
    hb = buildList({3});
    cout << rg96(ha, hb) << endl;
}