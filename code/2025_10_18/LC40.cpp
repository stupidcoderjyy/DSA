//
// Created by PC on 2025/10/19.
//

#include <algorithm>
#include <vector>

using std::vector;

vector<vector<int>> result;
vector<int> group;

//时间复杂度O(N*2^N) 空间复杂度O(N)
void Solve(const vector<int>& nums, int sum, int start) {
    if (sum == 0) {
        result.push_back(group);
        return;
    }
    int prev = -1;
    for (int i = start; i < nums.size() && nums[i] <= sum; ++i) {
        if (nums[i] == prev) {
            continue;
        }
        prev = nums[i];
        group.push_back(nums[i]);
        Solve(nums, sum - nums[i], i + 1);
        group.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    result = {};
    group = {};
    Solve(candidates, target, 0);
    return result;
}

int main() {
    vector vec = {10,1,2,7,6,1,5};
    combinationSum2(vec, 8);
    vec = {2,5,2,1,2};
    combinationSum2(vec, 5);
}