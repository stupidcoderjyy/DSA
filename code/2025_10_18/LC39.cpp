//
// Created by PC on 2025/10/19.
//

#include <algorithm>
#include <vector>

using std::vector;

//时间复杂度O(S) S是所有可行解的长度之和
//空间复杂度O(target)
void Solve(vector<vector<int>>& result, vector<int>& group, const vector<int>& nums, int sum, int start) {
    if (sum == 0) {
        result.push_back(group);
        return;
    }
    for (int i = start; i < nums.size() && nums[i] <= sum; ++i) {
        group.push_back(nums[i]);
        Solve(result, group, nums, sum - nums[i], i);
        group.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> group;
    Solve(result, group, candidates, target, 0);
    return result;
}

int main() {
    vector vec = {2,3,6,7};
    combinationSum(vec, 7);
    vec = {2,3,5};
    combinationSum(vec, 8);
    vec = {2};
    combinationSum(vec, 1);
}