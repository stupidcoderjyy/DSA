//
// Created by stupid_coder_jyy on 25-10-18.
//

#include <vector>
#include <deque>

using std::vector;
using std::deque;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(), right(), next() {}
    Node(int _val) : val(_val), left(), right(), next() {}
};

Node* connect(Node* root) {
    vector<int> result;
    if (!root) {
        return nullptr;
    }
    deque <Node*> nodes;
    nodes.push_back(root);
    while (!nodes.empty()) {
        int levelSize = nodes.size();
        Node *prev = nullptr;
        for (int i = 0; i < levelSize; i++) {
            auto *node = nodes.front();
            nodes.pop_front();
            if (prev) {
                prev->next = node;
            }
            prev = node;
            if (node->left) {
                nodes.push_back(node->left);
            }
            if (node->right) {
                nodes.push_back(node->right);
            }
        }
    }
    return root;
}