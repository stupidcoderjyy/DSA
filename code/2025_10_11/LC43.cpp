//
// Created by PC on 2025/10/11.
//

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;

//时间复杂度：O(mn) 空间复杂度：O(m+n)
string multiply(string num1, string num2) {
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    size_t arr_len = num1.length() + num2.length();
    std::vector num(arr_len, '0');
    int r = 0;
    //模拟竖式
    for (int i = 0; i < num1.length(); ++i) {
        for (int j = 0; j < num2.length(); ++j) {
            int v = r + (num[i + j] - '0') + (num1[i] - '0') * (num2[j] - '0');
            num[i + j] = static_cast<char>(v % 10 + '0');
            r = v / 10;
        }
        num[i + num2.length()] = static_cast<char>(r + '0');
        r = 0;
    }
    //删除末尾的0
    size_t len = arr_len;
    while (len > 1 && num[len - 1] == '0') {
        len--;
    }
    string result(num.data(), len);
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::cout << multiply("0", "0") << std::endl;
    std::cout << multiply("1", "2") << std::endl;
    std::cout << multiply("456", "9999") << std::endl;
    std::cout << multiply("9999", "456") << std::endl;
    return 0;
}