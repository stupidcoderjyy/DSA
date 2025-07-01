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

void removeNode(ListNode* p, ListNode* a) {
    p->next = a->next;
    delete a;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode header;
    header.next = head;
    int r = 0;
    ListNode* nl = &header, *nr = head;
    while (r != n - 1) {
        r++;
        nr = nr->next;
    }
    while (true) {
        if (!nr->next) {
            removeNode(nl, nl->next);
            return header.next;
        }
        nl = nl->next;
        nr = nr->next;
    }
}

//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
int main() {
    auto node = buildList({1,2,3,4,5});
    removeNthFromEnd(node, 2);
    node = buildList({1});
    removeNthFromEnd(node, 1);
    node = buildList({1,2});
    removeNthFromEnd(node, 1);
}