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

bool hasCycle(ListNode *head) {
    auto *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
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
    auto* list = build_list("1 2 3");
    list->next->next->next = list;
    std::cout << hasCycle(list) << '\n';

    list = build_list("1");
    std::cout << hasCycle(list) << '\n';

    list = build_list("1");
    list->next = list;
    std::cout << hasCycle(list) << std::endl;
}