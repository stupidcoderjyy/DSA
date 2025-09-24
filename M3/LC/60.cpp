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

//理解1：左子树最大值 < 当前结点值 < 右子树最小值
bool solve1(TreeNode* node, long long& min, long long& max) {
    if (!node->left && !node->right) {
        min = node->val;
        max = node->val;
        return true;
    }
    long long lMin, lMax, rMin, rMax;
    bool b1, b2;
    if (node->left) {
        b1 = solve1(node->left, lMin, lMax);
    } else {
        b1 = true;
        lMin = lMax = LLONG_MIN;
    }
    if (node->right) {
        b2 = solve1(node->right, rMin, rMax);
    } else {
        b2 = true;
        rMin = rMax = LLONG_MAX;
    }
    bool b3 = lMax < node->val && rMin > node->val;
    min = lMin == LLONG_MIN ? node->val : lMin;
    max = rMax == LLONG_MAX ? node->val : rMax;
    return b1 && b2 && b3;
}

// bool isValidBST(TreeNode* root) {
//     long long min, max;
//     return solve1(root, min, max);
// }

//理解2：当前节点值的合法区间
bool solve2(TreeNode* node, long long min, long long max) {
    if (!node) {
        return true;
    }
    return node->val > min && node->val < max
        && solve2(node->left, min, node->val)
        && solve2(node->right, node->val, max);
}

bool isValidBST(TreeNode* root) {
    return solve2(root, LLONG_MIN, LLONG_MAX);
}

//https://leetcode.cn/problems/validate-binary-search-tree/description/
int main() {
    auto* node = buildTree("1");
    cout << isValidBST(node) << endl;
    node = buildTree("5 12");
    cout << isValidBST(node) << endl;
    node = buildTree("5 18 x6");
    cout << isValidBST(node) << endl;
    node = buildTree("5 14 xx36");
    cout << isValidBST(node) << endl;
    node = buildTree("2 14 xx36");
    cout << isValidBST(node) << endl;
}