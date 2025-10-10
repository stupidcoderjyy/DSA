//
// Created by PC on 2025/10/9.
//

#include <iostream>
#include <deque>
#include <vector>
using std::vector;
using std::deque;

//时间复杂度：O(n) 空间复杂度：O(n)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    //维护一个递减队列
    for (int i = 0; i < nums.size(); ++i) {
        //弹出离开区间的数
        if (!dq.empty() && i - dq.front() >= k) {
            dq.pop_front();
        }
        //维护递减队列
        if (dq.empty() || nums[i] <= nums[dq.back()]) {
            dq.push_back(i);
        } else {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //front就是最大值
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

/*
3 8 1 3 -1 -3 5 3 6 7
 */
int main() {
    while (true) {
        int len, k;
        std::cin >> k >> len;
        if (!len) {
            break;
        }
        vector<int> vec(len);
        for (int i = 0; i < len; i++) {
            std::cin >> vec[i];
        }
        vec = maxSlidingWindow(vec, k);
        for (int i : vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}
