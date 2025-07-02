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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
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
    int d = abs(dl);
    auto* p = dl > 0 ? headA : headB;
    while (d > 0) {
        p = p->next;
        d--;
    }
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

//https://leetcode.cn/problems/intersection-of-two-linked-lists/
int main() {
    auto nodeA = buildList({4,1,8,4,5});
    auto nodeB = buildList({5,6,1});
    nodeB->next->next->next = nodeA->next->next;
    getIntersectionNode(nodeA, nodeB);
    nodeA = buildList({1,2});
    nodeB = buildList({3});
    nodeB->next = nodeA->next;
    getIntersectionNode(nodeA, nodeB);
    nodeA = buildList({1,2,3,4});
    nodeB = buildList({5,6});
    getIntersectionNode(nodeA, nodeB);
}