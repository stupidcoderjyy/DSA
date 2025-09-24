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

bool findPath(TreeNode* node, int target) {
    //错误：应当在叶节点返回，而不是空结点返回
    if (!node->left && !node->right) {
        return target == node->val;
    }
    if (node->left && findPath(node->left, target - node->val)) {
        return true;
    }
    if (node->right && findPath(node->right, target - node->val)) {
        return true;
    }
    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    return root && findPath(root, targetSum);
}

//https://leetcode.cn/problems/path-sum/
int main() {
    auto* root = buildTree("1 23");
    cout << hasPathSum(root, 3) << endl;
    cout << hasPathSum(root, 4) << endl;
    cout << hasPathSum(root, 5) << endl;
    root = buildTree("1 23 4x56");
    cout << hasPathSum(root, 7) << endl;
    cout << hasPathSum(root, 9) << endl;
    cout << hasPathSum(root, 10) << endl;
    cout << hasPathSum(root, 1) << endl;
    root = nullptr;
    cout << hasPathSum(root, 0) << endl;
    root = buildTree("1 2");
    cout << hasPathSum(root, 1) << endl;
}