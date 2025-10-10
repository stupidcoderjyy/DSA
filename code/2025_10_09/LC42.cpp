//
// Created by PC on 2025/10/9.
//

#include <iostream>
#include <stack>
#include <vector>
using std::vector;
using std::stack;

//时间复杂度：O(n) 空间复杂度：O(n)
int trap(const vector<int>& height) {
    stack<int> st;
    int result = 0, i = 0;
    while (i < height.size()) {
        //维护一个递减栈
        if (st.empty() || height[i] < height[st.top()]) {
            st.push(i++);
        } else if (st.size() == 1) {
            //缺少左墙壁
            st.pop();
            st.push(i++);
        } else {
            //能够形成水槽
            int bottom_h = height[st.top()];
            st.pop();
            int wall_h = std::min(height[st.top()], height[i]);
            result += (wall_h - bottom_h) * (i - st.top() - 1);
            //这一轮的左墙壁作为下一轮的底，故只弹出底部，也不修改i
        }
    }
    return result;
}

/*
5 1 2 1 2 1
5 3 2 1 2 3
*/
int main() {
    while (true) {
        int len;
        std::cin >> len;
        if (!len) {
            break;
        }
        vector<int> vec(len);
        for (int i = 0; i < len; i++) {
            std::cin >> vec[i];
        }
        std::cout << trap(vec) << std::endl;
    }
}
