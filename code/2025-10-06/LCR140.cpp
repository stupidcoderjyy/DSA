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

ListNode* trainingPlan(ListNode* head, int cnt) {
    auto* forward = head;
    for (int i = 0; i < cnt; ++i) {
        forward = forward->next;
    }
    while (forward) {
        forward = forward->next;
        head = head->next;
    }
    return head;
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
        int cnt;
        std::cin >> cnt;
        std::string s;
        std::getline(std::cin, s);
        auto* linked_list = build_list(s);
        std::cout << trainingPlan(linked_list, cnt)->val << std::endl;
        if (s.empty()) {
            return 0;
        }
    }
}