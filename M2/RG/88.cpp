//
// Created by PC on 25-7-1.
//

#include <vector>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
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
    delete a;
}

ListNode* rg88(ListNode* head) {
    ListNode header;
    header.next = head;
    ListNode *p = &header, *mp = nullptr, *ma = nullptr;
    int min = INT_MAX;
    while (true) {
        auto *a = p->next;
        if (!a) {
            if (mp && ma) {
                removeNode(mp, ma);
            }
            return header.next;
        }
        if (a->val < min) {
            min = a->val;
            mp = p;
            ma = a;
        }
        p = p->next;
    }
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* head = buildList({1,5,2,4});
    rg88(head);
}