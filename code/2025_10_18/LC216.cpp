//
// Created by PC on 2025/10/19.
//

#include <algorithm>
#include <vector>

using std::vector;

vector<vector<int>> result;
vector<int> group;

//时间复杂度O(N*2^N) 空间复杂度O(N) N为数字范围大小
int MinSum(int num, int count) {
    if (count > 0) {
        return (((num << 1) + count - 1) * count) >> 1;
    }
    return INT_MAX;
}

void Solve(int sum, int start, int count) {
    if (!sum && !count) {
        result.push_back(group);
        return;
    }
    for (int i = start; i <= 9 && sum >= MinSum(i, count); ++i) {
        group.push_back(i);
        Solve(sum - i, i + 1, count - 1);
        group.pop_back();
    }
}

vector<vector<int>> combinationSum3(int count, int target) {
    result = {};
    group = {};
    Solve(target, 1, count);
    return result;
}

int main() {
    combinationSum3(4, 1);
    combinationSum3(3, 7);
    combinationSum3(3, 9);
    combinationSum3(1, 20);
}