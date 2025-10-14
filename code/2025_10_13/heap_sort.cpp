//
// Created by PC on 2025/10/14.
//

#include <iostream>
#include <vector>

using std::vector;

void sink(vector<int>& vec, int i, int len);

//9 17 3 2 1 100 7 19 36 25
//二叉堆:完全二叉树 + 结点值 > 子树结点值
//时间复杂度：O(NlogN) 空间复杂度O(1)
//不稳定
void HeapSort(vector<int>& vec) {
    //完全二叉树的最后一个非叶结点: N/2 - 1
    //调整成最大堆 O(N)
    for (int i = vec.size() / 2 - 1; i >= 0; --i) {
        sink(vec, i, vec.size());
    }
    //O(NlogN)
    for (int i = vec.size() - 1; i > 0; --i) {
        //将顶部移到末尾,顶部一定是最大值
        std::swap(vec[i], vec[0]);
        //恢复最大堆
        sink(vec, 0, i);
    }
}

void sink(vector<int>& vec, int i, int len) {
    while (true) {
        //child = 第i个结点的最大子结点
        int child = (i << 1) + 1;
        if (child + 1 < len && vec[child] < vec[child + 1]) {
            ++child;
        }
        if (child >= len || vec[i] >= vec[child]) {
            break;
        }
        std::swap(vec[i], vec[child]);
        i = child;
    }
}

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n < 0) {
            break;
        }
        vector<int> vec(n);
        for (int& num : vec) {
            std::cin >> num;
        }
        HeapSort(vec);
        for (const int& num : vec) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}