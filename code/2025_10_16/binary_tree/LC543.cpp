//
// Created by PC on 2025/10/17.
//

#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::deque;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

//时间复杂度O(N) 最差|最好|平均空间复杂度O(N)|O(logN)|O(logN)
int MaxDepth(TreeNode* node, int& max_depth) {
    if (!node) {
        return 0;
    }
    int left = MaxDepth(node->left, max_depth);
    int right = MaxDepth(node->right, max_depth);
    max_depth = std::max(max_depth, left + right);
    return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int max_depth = 0;
    MaxDepth(root, max_depth);
    return max_depth;
}

TreeNode* BuildNode(const vector<int>& vec, vector<int>::const_iterator& it) {
    if (it == vec.end()) {
        return nullptr;
    }
    int i = *it++;
    return i < 0 ? nullptr : new TreeNode(i);
}

TreeNode* BuildTree(const vector<int>& vec) {
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
        auto* left = BuildNode(vec, it);
        auto* right = BuildNode(vec, it);
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

int main() {
    while (true) {
        int len;
        std::cin >> len;
        if (len < 0) {
            break;
        }
        std::vector<int> vec(len);
        for (int& v : vec) {
            std::cin >> v;
        }
        auto* root = BuildTree(vec);
        std::cout << diameterOfBinaryTree(root) << std::endl;
        delete root;
    }
    return 0;
}

