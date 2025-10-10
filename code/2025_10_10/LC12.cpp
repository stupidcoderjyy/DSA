#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using std::string;

int unit[8] = {1, 5, 10, 50, 100, 500, 1000, INT_MAX};
char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

//时间复杂度：O(1) 空间复杂度：O(1)
//过于麻烦，枚举每一位的所有情况即可
string intToRoman(int num) {
    std::stringstream ss;
    for (int i = 6; i >= 0; i -= 2) {
        //根据每一位开头的数字添加字符
        int first = num / unit[i];
        if (first == 4) {
            ss << symbol[i] << symbol[i + 1];
            num -= unit[i + 1] - unit[i];
        } else if (first == 9) {
            ss << symbol[i] << symbol[i + 2];
            num -= unit[i + 2] - unit[i];
        } else {
            while (num >= unit[i + 1]) {
                ss << symbol[i + 1];
                num -= unit[i + 1];
            }
            while (num >= unit[i]) {
                ss << symbol[i];
                num -= unit[i];
            }
        }
    }
    return ss.str();
}

int main() {
    std::cout << intToRoman(58) << std::endl;
    for (int i = 1; i <= 100; ++i) {
        std::cout << std::setw(20) << std::left << intToRoman(i);
        if (i % 5 == 4) {
            std::cout << std::endl;
        }
    }
}