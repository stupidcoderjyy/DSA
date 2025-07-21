//
// Created by stupid_coder_jyy on 25-7-21.
//

#include <string>
#include <algorithm>
#include <deque>
#include <deque>
#include <iostream>
using namespace std;

struct Node {
    char val;
    Node *lChild{}, *rChild{};
    Node(): val() {}
    explicit Node(char val): val(val) {}
};

Node* fromPreAndInOrder(const string& preorder, const string& inorder) {
    if (inorder.empty()) {
        return nullptr;
    }
    auto ch = preorder[0];
    auto* node = new Node(ch);
    auto m = inorder.find(ch);
    auto l1 = m;
    auto l2 = inorder.length() - m - 1;
    node->lChild = fromPreAndInOrder(preorder.substr(1, l1), inorder.substr(0, l1));
    node->rChild = fromPreAndInOrder(preorder.substr(1 + l1, l2), inorder.substr(m + 1, l2));
    return node;
}

Node* fromPostAndInOrder(const string& postorder, const string& inorder) {
    if (inorder.empty()) {
        return nullptr;
    }
    auto ch = postorder[postorder.length() - 1];
    auto* node = new Node(ch);
    auto m = inorder.find(ch);
    auto l1 = m, l2 = inorder.length() - m - 1;
    node->lChild = fromPostAndInOrder(postorder.substr(0, l1), inorder.substr(0, l1));
    node->rChild = fromPostAndInOrder(postorder.substr(l1, l2), inorder.substr(m + 1, l2));
    return node;
}

Node* fromLevelAndInOrder(const string& levelOrder, const string& inorder) {
    deque<Node*> parents;
    deque<string> inorders;
    auto* root = new Node(levelOrder[0]);
    parents.push_front(root);
    inorders.push_front(inorder);
    int i = 0;
    while (!parents.empty()) {
        auto parent = parents.back();
        auto s = inorders.back();
        parents.pop_back();
        inorders.pop_back();
        auto m = s.find(parent->val);
        auto s1 = s.substr(0, m), s2 = s.substr(m + 1, s.length() - m - 1);
        if (!s1.empty()) {
            parent->lChild = new Node(levelOrder[++i]);
            parents.push_front(parent->lChild);
            inorders.push_front(s1);
        }
        if (!s2.empty()) {
            parent->rChild = new Node(levelOrder[++i]);
            parents.push_front(parent->rChild);
            inorders.push_front(s2);
        }
    }
    return root;
}

void levelOrder(Node* root) {
    deque<Node*> deque;
    deque.push_front(root);
    while (!deque.empty()) {
        auto* node = deque.back();
        deque.pop_back();
        cout << node->val << " ";
        if (node->lChild) {
            deque.push_front(node->lChild);
        }
        if (node->rChild) {
            deque.push_front(node->rChild);
        }
    }
    cout << endl;
}

int main() {
    levelOrder(fromPreAndInOrder("ABCDEFGHI", "BCAEDGHFI"));
    levelOrder(fromPostAndInOrder("CBEHGIFDA", "BCAEDGHFI"));
    levelOrder(fromLevelAndInOrder("ABDCEFGIH", "BCAEDGHFI"));
}