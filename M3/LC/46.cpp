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

bool isSymmetric(TreeNode* na, TreeNode* nb) {
    if (!na && !nb) {
        return true;
    }
    if (na && nb && na->val == nb->val) {
        return isSymmetric(na->left, nb->right) && isSymmetric(na->right, nb->left);
    }
    return false;
}

bool isSymmetric(TreeNode* root) {
    return isSymmetric(root->left, root->right);
}

//https://leetcode.cn/problems/symmetric-tree/description/
int main() {
    auto* root = buildTree("1 22 3443");
    cout << isSymmetric(root) << endl;
    root = buildTree("1 22 x3x3");
    cout << isSymmetric(root) << endl;
    root = buildTree("1");
    cout << isSymmetric(root) << endl;
}