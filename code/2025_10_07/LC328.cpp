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

ListNode* oddEvenList(ListNode* head) {
    ListNode dh1, dh2, *n1 = &dh1, *n2 = &dh2;
    bool odd = true;
    while (head) {
        if (odd) {
            n1->next = head;
            n1 = head;
        } else {
            n2->next = head;
            n2 = head;
        }
        head = head->next;
        odd = !odd;
    }
    n1->next = dh2.next;
    n2->next = nullptr;
    return dh1.next;
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
        print_list(oddEvenList(linked_list));
        if (s.empty()) {
            return 0;
        }
    }
}