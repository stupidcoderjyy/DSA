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

void insert(ListNode* parent, ListNode* node) {
    node->next = parent->next;
    parent->next = node;
}

ListNode* insertionSortList(ListNode* head) {
    ListNode dummy_head(INT_MIN);
    dummy_head.next = head;
    auto* n = &dummy_head;
    while (n->next) {
        //跳过顺序正确的
        if (n->next->val > n->val) {
            n = n->next;
            continue;
        }
        //删除n.next
        auto* removed = n->next;
        n->next = removed->next;
        //结点插入到正确位置
        auto* n0 = &dummy_head;
        while (removed->val > n0->next->val) {
            n0 = n0->next;
        }
        insert(n0,  removed);
        //n不需要移动
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
        std::string s;
        std::getline(std::cin, s);
        auto* linked_list = build_list(s);
        print_list(insertionSortList(linked_list));
        if (s.empty()) {
            return 0;
        }
    }
}