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

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int hl = maxDepth(root->left);
    int hr = maxDepth(root->right);
    return std::max(hl, hr) + 1;
}

//https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
int main() {
    auto* root = buildTree("1 22 3443");
    cout << maxDepth(root) << endl;
    root = buildTree("1 x2 xxx3 xxxxxxx4");
    cout << maxDepth(root) << endl;
    root = buildTree("");
    cout << maxDepth(root) << endl;
    root = buildTree("1");
    cout << maxDepth(root) << endl;
}