//
// Created by PC on 2025/10/12.
//

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

//时间复杂度O(min(M,N)) 空间复杂度O(1)
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// TreeNode* BuildNode(const vector<int>& vec, vector<int>::const_iterator& it) {
//     if (it == vec.end()) {
//         return nullptr;
//     }
//     int i = *it++;
//     return i < 0 ? nullptr : new TreeNode(i);
// }
//
// TreeNode* BuildTree(const vector<int>& vec) {
//     if (vec.empty()) {
//         return nullptr;
//     }
//     deque<TreeNode*> deque;
//     auto it = vec.begin();
//     auto* root = new TreeNode(*it++);
//     deque.push_front(root);
//     while (it != vec.end()) {
//         auto node = deque.back();
//         deque.pop_back();
//         auto* left = BuildNode(vec, it);
//         auto* right = BuildNode(vec, it);
//         deque.push_front(left);
//         deque.push_front(right);
//         if (!node) {
//             continue;
//         }
//         node->left = left;
//         node->right = right;
//     }
//     return root;
// }
//
// int main() {
//     while (true) {
//         int len;
//         std::cin >> len;
//         std::vector<int> vec(len);
//         for (int& v : vec) {
//             std::cin >> v;
//         }
//         auto* root = BuildTree({1, 2, 3, 4, 5, 6, 7, 8});
//         std::cout << isSameTree(root);
//         delete root;
//     }
//     std::stringstream preorder, inorder, postorder;
//     Traversal(root, preorder, inorder, postorder);
//     std::cout << preorder.str() << '\n' << inorder.str() << '\n' << postorder.str() << std::endl;
// }