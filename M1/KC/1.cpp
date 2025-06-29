//
// Created by JYY on 25-6-29.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

//https://kamacoder.com/problempage.php?pid=1044
int main() {
    int h, w;
    cin >> h >> w;
    int map[h][w], sum[h + 1][w + 1];
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            cin >> map[r][c];
        }
    }
    for (int r = 0; r <= h; ++r) {
        sum[r][0] = 0;
    }
    for (int c = 0; c <= w; ++c) {
        sum[0][c] = 0;
    }
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            sum[r + 1][c + 1] = sum[r + 1][c] + sum[r][c + 1] - sum[r][c] + map[r][c];
        }
    }
    int res = INT_MAX;
    for (int r = 1; r < h; ++r) {
        res = min(res, abs(sum[h][w] - sum[r][w] - sum[r][w]));
    }
    for (int c = 1; c < w; ++c) {
        res = min(res, abs(sum[h][w] - sum[h][c] - sum[h][c]));
    }
    cout << res << endl;
}