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

void printVec(const vector<int>& vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> result;
int maxCount;

void solve(TreeNode* node, TreeNode*& prev, int& count) {
    if (!node) {
        return;
    }
    solve(node->left, prev, count);
    if (prev && prev->val != node->val) {
        count = 0;
    }
    count++;
    prev = node;

    if (count == maxCount) {
        result.push_back(node->val);
    } else if (count > maxCount) {
        maxCount = count;
        result.resize(1);
        result[0] = node->val;
    }
    solve(node->right, prev, count);
}

vector<int> findMode(TreeNode* root) {
    result = {};
    maxCount = 0;
    TreeNode* prev = nullptr;
    int count = 0;
    solve(root, prev, count);
    return result;
}

//https://leetcode.cn/problems/find-mode-in-binary-search-tree/
int main() {
    auto* node = buildTree("1");
    printVec(findMode(node));
    node = buildTree("1 11");
    printVec(findMode(node));
    node = buildTree("1 x2");
    printVec(findMode(node));
    node = buildTree("1 2");
    printVec(findMode(node));
    node = buildTree("1 12 xx2x xxxx2");
    printVec(findMode(node));
    node = buildTree("1 12 1x2x xxxx2");
    printVec(findMode(node));
}