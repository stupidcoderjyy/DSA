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

bool isBalanced(TreeNode* node, int& maxDepth) {
    if (!node) {
        maxDepth = 0;
        return true;
    }
    int hl, hr;
    if (isBalanced(node->left, hl) && isBalanced(node->right, hr)) {
        maxDepth = std::max(hl, hr) + 1;
        return std::abs(hr - hl) <= 1;
    }
    return false;
}

bool isBalanced(TreeNode* root) {
    int maxDepth;
    return isBalanced(root, maxDepth);
}

//https://leetcode.cn/problems/balanced-binary-tree/
int main() {
    auto* root = buildTree("1 23 xx45");
    cout << isBalanced(root) << endl;
    root = buildTree("1 x2 xxx3");
    cout << isBalanced(root) << endl;
    root = buildTree("");
    cout << isBalanced(root) << endl;
}