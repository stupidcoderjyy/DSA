//
// Created by PC on 2025/10/6.
//

#include <iomanip>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(), next() {}
    explicit ListNode(int val) : val(val), next() {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *new_next = nullptr, *node = head;
    while (node) {
        auto *new_parent = node->next;
        node->next = new_next;
        new_next = node;
        node = new_parent;
    }
    return new_next;
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
        std::string s;
        std::getline(std::cin, s);
        auto* linked_list = build_list(s);
        print_list(reverseList(linked_list));
        if (s.empty()) {
            return 0;
        }
    }
}