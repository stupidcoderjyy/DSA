//
// Created by PC on 25-7-1.
//

#include <vector>
#include <cmath>

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

void removeNode(ListNode* p, ListNode* a) {
    p->next = a->next;
}

void insertNode(ListNode* p, ListNode* a) {
    a->next = p->next;
    p->next = a;
}

ListNode* rg92(ListNode* head) {
    ListNode ha, hb;
    ha.next = head;
    ListNode *p = &ha;
    bool flag = true;
    while (true) {
        if (!p || !p->next) {
            return hb.next;
        }
        auto* a = p->next;
        if (flag) {
            p = p->next;
        } else {
            removeNode(p, a);
            insertNode(&hb, a);
        }
        flag = !flag;
    }
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* head = buildList({1,2,3,4});
    rg92(head);
    head = buildList({1});
    rg92(head);
    head = nullptr;
    rg92(head);
}