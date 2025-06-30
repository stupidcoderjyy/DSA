//
// Created by JYY on 25-6-30.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next{};
    ListNode *prev{};
    ListNode() : val(0) {}
    explicit ListNode(int x) : val(x) {}
};

class MyLinkedList {
private:
    ListNode* header;
    int size;
public:
    MyLinkedList() {
        header = new ListNode;
        header->next = header;
        header->prev = header;
        size = 0;
    }

    int get(int index) {
        return checkIndex(index) ? locate(index)->val : -1;
    }

    void addAtHead(int val) {
        insert(header, new ListNode(val));
    }

    void addAtTail(int val) {
        insert(header->prev, new ListNode(val));
    }

    void addAtIndex(int index, int val) {
        if (index >= 0 && index <= size) {
            insert(index == 0 ? header : locate(index - 1), new ListNode(val));
        }
    }

    void deleteAtIndex(int index) {
        if (checkIndex(index)) {
            remove(locate(index));
        }
    }
private:
    bool checkIndex(int i) {
        return i >= 0 && i < size;
    }

    ListNode *locate(int pos) {
        ListNode* node = header;
        if (pos < (size >> 1)) {
            int i = -1;
            while (i < pos) {
                node = node->next;
                i++;
            }
        } else {
            int i = size;
            while (i > pos) {
                node = node->prev;
                i--;
            }
        }
        return node;
    }
    void insert(ListNode* parent, ListNode* node) {
        auto* na = parent->next;
        parent->next = node;
        node->prev = parent;
        node->next = na;
        na->prev = node;
        size++;
    }
    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        size--;
    }
};

//https://leetcode.cn/problems/design-linked-list/
int main() {
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtTail(4);
    list.addAtIndex(4, 5);
    cout << list.get(0) << endl;
    cout << list.get(1) << endl;
    cout << list.get(2) << endl;
    cout << list.get(3) << endl;
}