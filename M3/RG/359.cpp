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

TreeNode* buildNode(const vector<int>& vec, vector<int>::const_iterator& it) {
    if (it == vec.end()) {
        return nullptr;
    }
    int i = *it++;
    return i < 0 ? nullptr : new TreeNode(i);
}

TreeNode* buildTree(const vector<int>& vec) {
    if (vec.empty()) {
        return nullptr;
    }
    deque<TreeNode*> deque;
    auto it = vec.begin();
    auto* root = new TreeNode(*it++);
    deque.push_front(root);
    while (it != vec.end()) {
        auto node = deque.back();
        deque.pop_back();
        auto* left = buildNode(vec, it);
        auto* right = buildNode(vec, it);
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

void solve(const vector<int>& pre, vector<int>& post, int l1, int r1, int l2, int r2) {
    if (l1 > r1) {
        return;
    }
    post[r2] = pre[l1];
    int len = (r1 - l1) / 2;
    solve(pre, post, l1 + 1, l1 + len, l2, l2 + len - 1);
    solve(pre, post, l1 + len + 1, r1, l2 + len, r2 - 1);
}

vector<int> rg359(const vector<int>& pre) {
    vector<int> post;
    post.resize(pre.size());
    solve(pre, post, 0, pre.size() - 1, 0, pre.size() - 1);
    return post;
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    auto result = rg359({1});
    result = rg359({1,2,3});
    result = rg359({1,2,4,5,3,6,7});
}