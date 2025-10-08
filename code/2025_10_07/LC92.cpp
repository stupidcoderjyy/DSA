//
// Created by PC on 2025/10/7.
//

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(), next() {}
    explicit ListNode(int val) : val(val), next() {}
};

/*
2 4 1 2 3 4 5
1 5 1 2 3 4 5
1 4 1 2 3 4 5
2 5 1 2 3 4 5
1 1 5
0 0

*/
ListNode* reverseBetween(ListNode* head, int left, int right) {
    //TODO 基于pre, cur, next指针的翻转
    ListNode dummy_head;
    dummy_head.next = head;
    auto *pre = &dummy_head;
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }
    ListNode *cur = pre->next;
    for (int i = 0; i < right - left; i++) {
        auto *next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummy_head.next;
}

ListNode* build_list(const std::string& s) {
    std::vector<int> nums;
    std::stringstream ss(s);
    std::string token;
    while (ss >> token) {
        nums.push_back(std::stoi(token));
    }
    if (nums.empty()) return nullptr;
    auto head = new ListNode(nums[0]);
    auto* curr = head;
    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

void print_list(const ListNode* node) {
    while (node) {
        std::cout << std::left << std::setw(3) << node->val;
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    while (true) {
        int l, r;
        std::cin >> l >> r;
        if (l == 0 && r == 0) {
            return 0;
        }
        std::string s;
        std::getline(std::cin, s);
        auto* linked_list = build_list(s);
        print_list(reverseBetween(linked_list, l, r));
    }
}