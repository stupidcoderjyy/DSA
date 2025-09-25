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

TreeNode* buildNode(int val) {
    if (val == -1) {
        return nullptr;
    }
    return new TreeNode(val);
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
        auto* left = buildNode(*it++);
        auto* right = buildNode(*it++);
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

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode h(INT_MAX);
    h.left = root;
    auto* n = root, *p = &h;
    while (n) {
        if (key == n->val) {
            break;
        }
        p = n;
        n = key < n->val ? n->left : n->right;
    }
    if (!n) {
        return root;
    }
    //找到n右子树的最左侧结点
    auto* r = n->right, *l = n->left, *rb = r;
    while (rb) {
        if (rb->left) {
            rb = rb->left;
        } else {
            break;
        }
    }
    //删除并设置新的结点
    delete n;
    if (rb) {
        rb->left = l;
        n = r;
    } else {
        n = l;
    }
    //将新的节点挂到双亲上
    if (key < p->val) {
        p->left = n;
    } else {
        p->right = n;
    }
    return h.left;
}

//https://leetcode.cn/problems/insert-into-a-binary-search-tree/
int main() {
    auto* node = buildTree({{5,3,7,2,4,6,8}});
    deleteNode(node, 5);
    node = buildTree({{5,3,7,2,4,6,8}});
    deleteNode(node, 3);
    node = buildTree({{5,3,7,2,4,6,8}});
    deleteNode(node, 2);
    node = buildTree({{5,3,7,2,4,6,8}});
    deleteNode(node, 8);
    node = buildTree({{5,3,7,2,4,6,8}});
    deleteNode(node, 12);
    node = nullptr;
    deleteNode(node, 8);
}