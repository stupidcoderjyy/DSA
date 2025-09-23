//
// Created by PC on 2025/9/23.
//

#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
//
// Created by PC on 2025/9/22.
//
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left{}, *right{};
    TreeNode(): val() {}
    explicit TreeNode(int val): val(val) {}
};

TreeNode* buildNode(string& s, string::iterator& it) {
    if (it == s.end()) {
        return nullptr;
    }
    auto ch = *it++;
    return ch == 'x' ? nullptr : new TreeNode(ch - '0');
}

TreeNode* buildTree(string s) {
    if (s.empty()) {
        return nullptr;
    }
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    deque<TreeNode*> deque;
    auto it = s.begin();
    auto* root = buildNode(s, it);
    deque.push_front(root);
    while (it != s.end()) {
        auto node = deque.back();
        deque.pop_back();
        auto* left = buildNode(s, it);
        auto* right = buildNode(s, it);
        deque.push_front(left);
        deque.push_front(right);
        if (!node) {
            continue;
        }
        node->left = left;
        node->right = right;
    }
    return root;
}

int findBottomLeftValue(TreeNode* root) {
    deque<TreeNode*> nodes;
    nodes.push_back(root);
    int first = 0;
    while (!nodes.empty()) {
        int levelSize = nodes.size();
        first = nodes.front()->val;
        for (int i = 0 ; i < levelSize ; i++) {
            auto* node = nodes.front();
            nodes.pop_front();
            if (node->left) {
                nodes.push_back(node->left);
            }
            if (node->right) {
                nodes.push_back(node->right);
            }
        }
    }
    return first;
}

//https://leetcode.cn/problems/find-bottom-left-tree-value/
int main() {
    auto* root = buildTree("2 13");
    cout << findBottomLeftValue(root) << endl;
    root = buildTree("1 23 4x56 xxxx7");
    cout << findBottomLeftValue(root) << endl;
}