//
// Created by JYY on 25-6-29.
//

#include <iostream>
#include <vector>

using namespace std;

//https://kamacoder.com/problempage.php?pid=1070
int main() {
    int n;
    cin >> n;
    int num[n], sum[n + 1];
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        sum[i + 1] = sum[i] + num[i];
    }
    vector<int> vec;
    int l, r;
    while (cin >> l >> r) {
        cout << sum[r + 1] - sum[l] << endl;
    }
}