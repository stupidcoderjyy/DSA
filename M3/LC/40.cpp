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

vector<int> largestValues(TreeNode* root) {
    vector<int> result;
    if (!root) {
        return result;
    }
    deque<TreeNode*> nodes;
    nodes.push_back(root);
    while (!nodes.empty()) {
        int levelSize = nodes.size();
        int max = INT_MIN;
        for (int i = 0 ; i < levelSize ; i++) {
            auto* node = nodes.front();
            nodes.pop_front();
            max = std::max(max, node->val);
            if (node->left) {
                nodes.push_back(node->left);
            }
            if (node->right) {
                nodes.push_back(node->right);
            }
        }
        result.push_back(max);
    }
    return result;
}

//https://leetcode.cn/problems/find-largest-value-in-each-tree-row
int main() {
    auto* root = buildTree("1 23 45x8 xx97xx5");
    largestValues(root);
}