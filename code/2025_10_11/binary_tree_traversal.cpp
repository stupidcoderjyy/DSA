//
// Created by PC on 2025/10/11.
//

#include <stack>
#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>

using std::vector;
using std::stack;
using std::deque;
using std::string;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(), left(), right() {}
    explicit TreeNode(int val) : val(val), left(), right() {}
};

void Traversal(
        TreeNode* root,
        std::stringstream& preorder,
        std::stringstream& inorder,
        std::stringstream& postorder) {
    stack<TreeNode*> nodes;
    stack<bool> isLeft;
    nodes.push(root);
    isLeft.push(false);
    while (true) {
        while (nodes.top()) {
            //前序遍历访问点
            preorder << nodes.top()->val << ' ';
            nodes.push(nodes.top()->left);
            isLeft.push(true);
        }
        while (true) {
            auto isLeftChild = isLeft.top();
            nodes.pop();
            isLeft.pop();
            if (nodes.empty()) {
                return;
            }
            if (isLeftChild) {
                //中序遍历访问点
                inorder << nodes.top()->val << ' ';
                nodes.push(nodes.top()->right);
                isLeft.push(false);
                break;
            }
            //后序遍历访问点
            postorder << nodes.top()->val << ' ';
        }
    }
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
    auto* root = BuildTree({1, 2, 3, 4, 5, 6, 7, 8});
    std::stringstream preorder, inorder, postorder;
    Traversal(root, preorder, inorder, postorder);
    std::cout << preorder.str() << '\n' << inorder.str() << '\n' << postorder.str() << std::endl;
}