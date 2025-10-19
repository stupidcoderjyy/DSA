//
// Created by PC on 2025/10/19.
//
#include <vector>

using std::vector;

vector<vector<int>> result;
vector<int> group;
vector<bool> index_to_visited;

//时间复杂度O(N*2^N) 空间复杂度O(N)
void Solve(vector<int>& nums) {
    if (group.size() == nums.size()) {
        result.push_back(group);
        return;
    }
    for (int i = 0; i < nums.size() ; ++i) {
        if (index_to_visited[i]) {
            continue;
        }
        group.push_back(nums[i]);
        index_to_visited[i] = true;
        Solve(nums);
        group.pop_back();
        index_to_visited[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    result = {};
    group = {};
    index_to_visited = vector(nums.size(), false);
    Solve(nums);
    return result;
}

int main() {
    vector vec = {1,2,3};
    permute(vec);
    vec = {0,1};
    permute(vec);
}