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

ListNode* middleNode(ListNode* head) {
    auto* fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
        if (s.empty()) {
            return 0;
        }
        auto* linked_list = build_list(s);
        std::cout << middleNode(linked_list)->val << std::endl;
    }
}