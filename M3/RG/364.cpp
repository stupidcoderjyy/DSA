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

bool solve(const vector<int>& tree, int n, long long min, long long max) {
    if (n >= tree.size() || tree[n] < 0) {
        return true;
    }
    return tree[n] > min && tree[n] < max
        && solve(tree, left(n), min, tree[n])
        && solve(tree, right(n), tree[n], max);
}

bool rg364(const vector<int>& tree) {
    return solve(tree, 0, LLONG_MIN, LLONG_MAX);
}

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int main() {
    cout << rg364({1}) << endl;
    cout << rg364({5,1,2}) << endl;
    cout << rg364({5,1,8,-1,6}) << endl;
    cout << rg364({5,1,4,-1,-1,3,6}) << endl;
    cout << rg364({2,1,4,-1,-1,3,6}) << endl;
}