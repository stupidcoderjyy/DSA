//
// Created by PC on 2025/10/7.
//

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(), next() {}
    explicit ListNode(int val) : val(val), next() {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode header;
    header.next = head;
    auto* p = &header;
    while (true) {
        auto* a = p->next;
        if (!a || !a->next) {
            return header.next;
        }
        auto* b = a->next;
        p->next = b;
        a->next = b->next;
        b->next = a;
        p = a;
    }
}
