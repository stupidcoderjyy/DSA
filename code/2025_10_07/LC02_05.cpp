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

ListNode* sum(ListNode* n1, ListNode* n2, bool& carry) {
    if (!n1 && !n2 && !carry) {
        return nullptr;
    }
    int sum = carry;
    sum += n1 ? n1->val : 0;
    sum += n2 ? n2->val : 0;
    carry = sum > 9;
    return new ListNode(sum % 10);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool carry = false;
    ListNode dummy_head;
    dummy_head.next = l1;
    ListNode *n = &dummy_head;
    while (n) {
        n->next = sum(l1, l2, carry);
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
        n = n->next;
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

/*
1
1 1
1
9
9 9
1
*/

int main() {
    while (true) {
        std::string s1;
        std::getline(std::cin, s1);
        if (s1.empty()) {
            return 0;
        }
        std::string s2;
        std::getline(std::cin, s2);
        print_list(addTwoNumbers(build_list(s1), build_list(s2)));
    }
}