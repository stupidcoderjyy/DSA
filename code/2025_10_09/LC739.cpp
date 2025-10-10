//
// Created by PC on 2025/10/9.
//

#include <iostream>
#include <stack>
#include <vector>
using std::vector;
using std::stack;

//时间复杂度：O(n) 空间复杂度：O(n)
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> st;
    vector result(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); ++i) {
        //维护递减栈
        if (st.empty() || temperatures[i] <= temperatures[st.top()]) {
            st.push(i);
        } else {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    return result;
}

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
        vec = dailyTemperatures(vec);
        for (int i = 0; i < len; i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }
}
