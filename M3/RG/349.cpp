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

#define left(n) (((n + 1) << 1) - 1)
#define right(n) (((n + 1) << 1))

int solve(const vector<int>& tree, int n, int n1, int n2) {
    if (n >= tree.size() || tree[n] == 0) {
        return 0;
    }
    if (tree[n] == n1 || tree[n] == n2) {
        return tree[n];
    }
    int t1 = solve(tree, left(n), n1, n2);
    int t2 = solve(tree, right(n), n1, n2);
    if (t1 && t2) {
        return tree[n];
    }
    return t1 ? t1 : t2;
}

int rg349(const vector<int>& tree, int n1, int n2) {
    return solve(tree, 0, n1, n2);
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    cout << rg349({1,2}, 1, 2) << endl;
    cout << rg349({1,2,3}, 2, 3) << endl;
    cout << rg349({1,2,3,4,5}, 4,3) << endl;
    cout << rg349({1,2,3,4,5}, 3,4) << endl;
    cout << rg349({1,2,3,4,5}, 2,4) << endl;
    cout << rg349({1,2,3,4,5}, 4,2) << endl;
}