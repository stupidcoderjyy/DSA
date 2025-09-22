//
// Created by PC on 25-7-1.
//

#include <vector>

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

ListNode* swapPairs(ListNode* head) {
    ListNode header;
    header.next = head;
    auto* p = &header;
    while (true) {
        auto* a = p->next;
        if (!a || !a->next) {
            return header.next;
        }
        auto* b = a->next;
        p->next = b;
        a->next = b->next;
        b->next = a;
        p = a;
    }
}

//https://leetcode.cn/problems/swap-nodes-in-pairs/description/
int main() {
    auto node = buildList({1,2,3,4});
    swapPairs(node);
    node = nullptr;
    swapPairs(node);
    node = buildList({1});
    swapPairs(node);
}