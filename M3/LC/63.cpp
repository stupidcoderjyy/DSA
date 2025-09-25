//
// Created by PC on 2025/9/23.
//

#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
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

TreeNode* target1;
TreeNode* target2;


//思路1：保存结点属性（非父结点 | p的父亲 | q的父亲 | p和q的父亲），返回第一个标志3的结点
TreeNode* solve1(TreeNode* node, int& flag) {
    flag = 0;
    if (!node) {
        return nullptr;
    }
    if (node == target1) {
        flag = 1;
    } else if (node == target2) {
        flag = 2;
    }
    int f1, f2;
    if (auto* r = solve1(node->left, f1)) {
        return r;
    }
    flag |= f1;
    if (flag == 3) {
        return node;
    }
    if (auto* r = solve1(node->right, f2)) {
        return r;
    }
    flag |= f2;
    return flag == 3 ? node : nullptr;
}

// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     target1 = p;
//     target2 = q;
//     int f;
//     return solve1(root, f);
// }

//思路2：找到第一个左右子树都存在目标结点的结点
TreeNode* solve2(TreeNode* node) {
    if (!node || node == target1 || node == target2) {
        return node;
    }
    auto* nl = solve2(node->left);
    auto* nr = solve2(node->right);
    if (nl && nr) {
        return node;
    }
    return nl ? nl : nr;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    target1 = p;
    target2 = q;
    return solve2(root);
}

//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
int main() {
    auto* node = buildTree("12");
    cout << lowestCommonAncestor(node, node, node->left)->val << endl;
    node = buildTree("123");
    cout << lowestCommonAncestor(node, node->left, node->right)->val << endl;
    node = buildTree("12345");
    cout << lowestCommonAncestor(node, node->left->left, node->right)->val - 1 << endl;
    cout << lowestCommonAncestor(node, node->right, node->left->left)->val - 1 << endl;
    cout << lowestCommonAncestor(node, node->left->left, node->left)->val - 2 << endl;
    cout << lowestCommonAncestor(node, node->left, node->left->left)->val - 2 << endl;
}