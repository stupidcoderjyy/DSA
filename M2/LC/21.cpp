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

ListNode *detectCycle(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    ListNode *f = head, *s = head;
    while (f != s) {
        if (!f->next || !f->next->next) {
            return nullptr;
        }
        f = f->next->next;
        s = s->next;
    }
    f = head;
    while (f != s) {
        f = f->next;
        s = s->next;
    }
    return f;
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* head = buildList({3,2,0,-4});
    head->next->next->next->next = head->next;
    detectCycle(head);
    head = buildList({1,2});
    head->next->next = head;
    detectCycle(head);
    head = buildList({1});
    detectCycle(head);
}