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

int solve(TreeNode* root) {
    if (!root->left) {
        return 1 + (root->right ? solve(root->right) : 0);
    }
    if (!root->right) {
        return 1 + solve(root->left);
    }
    return 1 + std::min(solve(root->left), solve(root->right));
}

int minDepth(TreeNode* root) {
    return root ? solve(root) : 0;
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    auto* root = buildTree("1 22 3443");
    cout << minDepth(root) << endl;
    root = buildTree("1 2x x3");
    cout << minDepth(root) << endl;
    root = buildTree("");
    cout << minDepth(root) << endl;
    root = buildTree("1");
    cout << minDepth(root) << endl;
}