//
// Created by PC on 2025/10/7.
//

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(), next() {}
    explicit ListNode(int val) : val(val), next() {}
};

ListNode *detectCycle(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    ListNode *f = head, *s = head;
    //判断是否有环
    while (true) {
        if (!f->next || !f->next->next) {
            return nullptr;
        }
        f = f->next->next;
        s = s->next;
        if (f == s) {
            break;
        }
    }
    //从相遇点和表头开始，同时移动，在环入口处再次相遇
    f = head;
    while (true) {
        if (f == s) {
            return f;
        }
        f = f->next;
        s = s->next;
    }
}
