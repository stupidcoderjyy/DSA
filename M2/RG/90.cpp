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
    delete a;
}

ListNode* rg90(ListNode* head, int min, int max) {
    ListNode header;
    header.next = head;
    ListNode *p = &header;
    while (true) {
        if (!p || !p->next) {
            return header.next;
        }
        auto *a = p->next;
        if (a->val >= min && a->val <= max) {
            removeNode(p, a);
        } else {
            p = p->next;
        }
    }
}

//https://leetcode.cn/problems/linked-list-cycle-ii/
int main() {
    auto* head = buildList({1,3,4,7,2,0});
    rg90(head, 0, 2);
    head = buildList({1});
    rg90(head, 1, 1);
    head = nullptr;
    rg90(head, 1, 1);
}