//
// Created by JYY on 25-6-30.
//

//https://leetcode.cn/problems/remove-linked-list-elements/

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    ListNode* b = head;
    ListNode* c = head->next;
    b->next = nullptr;
    while (true) {
        if (!c) {
            return b;
        }
        auto* cn = c->next;
        c->next = b;
        b = c;
        c = cn;
    }
}

ListNode *buildList(const vector<int> &vec) {
    ListNode header;
    ListNode *parent = &header;
    for (auto i: vec) {
        parent->next = new ListNode(i);
        parent = parent->next;
    }
    return header.next;
}

//https://leetcode.cn/problems/reverse-linked-list/
int main() {
    auto node = buildList({1,2,3});
    reverseList(node);
    node = nullptr;
    reverseList(node);
    node = buildList({1});
    reverseList(node);
}