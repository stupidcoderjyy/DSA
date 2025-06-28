//
// Created by JYY on 25-6-28.
//
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector M(n, vector(n, 0));
    int left = 0, top = 0, right = n - 1, down = right;
    int num = 1;
    while (left <= right && top <= down) {
        for (int i = left; i <= right; ++i) {
            M[top][i] = num++;
        }
        top++;
        for (int i = top; i <= down; ++i) {
            M[i][right] = num++;
        }
        right--;
        for (int i = right; i >= left; --i) {
            M[down][i] = num++;
        }
        down--;
        for (int i = down; i >= top; --i) {
            M[i][left] = num++;
        }
        left++;
    }
    return M;
}

#define test(x) cout << x << endl

//https://leetcode.cn/problems/spiral-matrix-ii/
int main() {
    generateMatrix(1);
    generateMatrix(2);
    generateMatrix(3);
    generateMatrix(4);
}