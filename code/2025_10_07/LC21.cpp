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

ListNode* next_node(ListNode*& n1, ListNode*& n2) {
    ListNode* result;
    if (!n1 || !n2) {
        result = n1 ? n1 : n2;
        if (n1) {
            n1 = n1->next;
        }
        if (n2) {
            n2 = n2->next;
        }
    } else if (n1->val < n2->val) {
        result = n1;
        n1 = n1->next;
    } else {
        result = n2;
        n2 = n2->next;
    }
    return result;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy_head, *n = &dummy_head;
    while (n) {
        n->next = next_node(list1, list2);
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

int main() {
    while (true) {
        std::string s1;
        std::getline(std::cin, s1);
        std::string s2;
        std::getline(std::cin, s2);
        print_list(mergeTwoLists(build_list(s1), build_list(s2)));
        if (s1.empty() && s2.empty()) {
            return 0;
        }
    }
}