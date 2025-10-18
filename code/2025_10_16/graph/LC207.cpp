//
// Created by PC on 2025/10/17.
//

#include <iostream>
#include <queue>
#include <vector>
using std::vector;

//判断有向图是否存在环，拓扑排序法
//时间复杂度O(V+E) 空间复杂度O(V+E)
bool Solve1(int num_courses, const vector<vector<int>>& prerequisites) {
    // 先修课程 → 后续课程
    // 构造邻接表 计算结点入度
    vector<vector<int>> map(num_courses);
    vector in_degree(num_courses, 0);
    for (const auto& vec : prerequisites) {
        map[vec[1]].push_back(vec[0]);
        in_degree[vec[0]]++;
    }
    //将零度结点加入队列 （即可以直接学习的课程）
    std::queue<int> q;
    for (int i = 0; i < num_courses; ++i) {
        if (!in_degree[i]) {
            q.push(i);
        }
    }
    //学习所有能学的课程
    int completed = 0;
    while (!q.empty()) {
        //学习课程
        int course = q.front();
        q.pop();
        completed++;
        //学习后续课程
        for (const int& next_course : map[course]) {
            in_degree[next_course]--;
            if (!in_degree[next_course]) {
                q.push(next_course);
            }
        }
    }
    //是否能够学完
    return completed == num_courses;
}

bool hasCircle(int course, vector<int>& state, const vector<vector<int>>& map) {
    if (state[course] == 2) {
        return false;   //已完成学习
    }
    if (state[course] == 1) {
        return true;
    }
    state[course] = 1; //学习中
    for (const int& i : map[course]) {
        if (hasCircle(i, state, map)) {
            return true;
        }
    }
    state[course] = 2; //学习中
    return false;
}

//判断有向图是否存在环，DFS法
//时间复杂度O(V+E) 空间复杂度O(V+E)
bool Solve2(int num_courses, const vector<vector<int>>& prerequisites) {
    vector<vector<int>> map(num_courses);
    for (const auto& pre : prerequisites) {
        map[pre[1]].push_back(pre[0]);
    }
    vector state(num_courses, 0);
    for (int i = 0; i < num_courses; i++) {
        if (hasCircle(i, state, map)) {
            return false;
        }
    }
    return true;
}

bool canFinish(int numCourses, const vector<vector<int>>& prerequisites) {
    return Solve2(numCourses, prerequisites);
}

int main() {
    std::cout << canFinish(2, {{1,0}}) << std::endl;
    std::cout << canFinish(2, {{1,0},{0,1}}) << std::endl;
    std::cout << canFinish(3, {{0,1},{1,2}}) << std::endl;
    std::cout << canFinish(3, {{0,1},{1,2},{2,1}}) << std::endl;
    std::cout << canFinish(3, {{0,1},{0,2}}) << std::endl;
}
