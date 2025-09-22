//
// Created by PC on 25-7-14.
//

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class MyQueue {
private:
    deque<int> deque;
public:
    MyQueue() {}

    void push(int x) {
        while (!deque.empty() && deque.back() < x) {
            deque.pop_back();
        }
        deque.push_back(x);
    }

    void pop(int x) {
        if (!deque.empty() && deque.front() == x) {
            deque.pop_front();
        }
    }

    int top() const {
        return deque.front();
    }

    bool empty() const {
        return deque.empty();
    }
};

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    MyQueue queue;
    vector<int> res;
    res.reserve(nums.size() - k + 1);
    int j;
    for (j = 0; j < k; ++j) {
        queue.push(nums[j]);
    }
    res.push_back(queue.top());
    int i = 0;
    while (j < nums.size()) {
        queue.pop(nums[i++]);
        queue.push(nums[j++]);
        res.push_back(queue.top());
    }
    return res;
}

//https://leetcode.cn/problems/sliding-window-maximum/
int main() {
    maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3);
    maxSlidingWindow({1,3,1,2,0,5}, 3);
    maxSlidingWindow({1}, 1);
}