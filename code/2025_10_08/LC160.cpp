//
// Created by PC on 2025/10/8.
//

#include <cmath>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(), next() {}
    explicit ListNode(int val) : val(val), next() {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //计算两个链表长度差
    int dl = 0;
    ListNode* node = headA;
    while (node) {
        dl++;
        node = node->next;
    }
    node = headB;
    while (node) {
        dl--;
        node = node->next;
    }
    int d = std::abs(dl);
    //长度短的链表，指针先前进dl步
    auto* p = dl > 0 ? headA : headB;
    while (d > 0) {
        p = p->next;
        d--;
    }
    //两个链表同时前进，直至相交或者同时为空
    auto* p1 = dl > 0 ? p : headA;
    auto* p2 = dl < 0 ? p : headB;
    while (true) {
        if (!p1 || !p2) {
            return nullptr;
        }
        if (p1 == p2) {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
}