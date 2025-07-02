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

ListNode *removeElements(ListNode *head, int val) {
    ListNode tempHeader(-1);
    tempHeader.next = head;
    head = &tempHeader;
    while (true) {
        if (!head || head->next == nullptr) {
            return tempHeader.next;
        }
        if (head->next->val == val) {
            head->next = head->next->next;
        } else {
            head = head->next;
        }
    }
}

ListNode* buildList(const vector<int> &vec) {
    ListNode header;
    ListNode* parent = &header;
    for (auto i : vec) {
        parent->next = new ListNode(i);
        parent = parent->next;
    }
    return header.next;
}

// https://leetcode.cn/problems/remove-linked-list-elements/description/
int main() {
    auto node = buildList({1, 2, 6, 3, 4, 5, 6});
    removeElements(node, 6);
    node = nullptr;
    removeElements(node, 1);
    node = buildList({7,7,7,7});
    removeElements(node, 7);
}