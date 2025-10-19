//
// Created by PC on 2025/10/19.
//

#include <vector>

using std::vector;

vector<vector<int>> result;
vector<int> group;

//时间复杂度O(C(n,k)*k) 空间复杂度O(k)
void Combine(int start, int end, int count) {
    if (!count) {
        result.push_back(group);
        return;
    }
    for (int i = start; i <= end - count + 1; ++i) {
        group.push_back(i);
        Combine(i + 1, end, count - 1);
        group.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    result = {};
    group = {};
    Combine(1, n, k);
    return result;
}

int main() {
    combine(1, 1);
    combine(2, 2);
    combine(4, 2);
}