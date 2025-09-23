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

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    deque<Node*> nodes;
    nodes.push_back(root);
    while (!nodes.empty()) {
        vector<int> level;
        int levelSize = nodes.size();
        for (int i = 0 ; i < levelSize ; i++) {
            auto* node = nodes.front();
            nodes.pop_front();
            level.push_back(node->val);
            for (auto child : node->children) {
                if (child) {
                    nodes.push_back(child);
                }
            }
        }
        result.push_back(level);
    }
    return result;
}

//https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
int main() {
}