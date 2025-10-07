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

ListNode* middleNode(ListNode* head) {
    auto* fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(ListNode* head) {
    auto* second_start = reverseList(middleNode(head));
    auto *n1 = head, *n2 = second_start;
    while (n2) {
        if (n1->val != n2->val) {
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
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

int main() {
    while (true) {
        std::string s;
        std::getline(std::cin, s);
        auto* linked_list = build_list(s);
        std::cout << isPalindrome(linked_list) << std::endl;
        if (s.empty()) {
            return 0;
        }
    }
}