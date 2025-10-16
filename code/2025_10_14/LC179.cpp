//
// Created by PC on 2025/10/16.
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

//时间复杂度O(NlogN) 空间复杂度O(N)
string largestNumber(vector<int>& numbers) {
    vector<string> s_numbers;
    s_numbers.reserve(numbers.size());
    for (const int& num : numbers) {
        s_numbers.push_back(std::to_string(num));
    }
    /*
     * 定义 A > B = AB > BA
     * 下证 A > B && B > C → ABC最大
     * 1) ACB: ABC = A(BC) > A(CB)
     * 2) B(AC|CA): ABC = (AB)C > BAC = B(AC) > BCA
     * 3) C(AB|BA): ABC = A(BC) > A(CB) = (AC)B > CAB = C(AB) > CBA
     * 即证
     *
     * 故只需要按照A > B的规则进行排序，然后合并即可
     */
    std::sort(s_numbers.begin(), s_numbers.end(), [](const string &s1, const string &s2) {
        return s1 + s2 > s2 + s1;
    });
    if (s_numbers.empty() || s_numbers[0] == "0") {
        return "0";
    }
    std::stringstream ss;
    for (const auto& s : s_numbers) {
        ss << s;
    }
    return ss.str();
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
        std::cout << largestNumber(vec) << std::endl;
    }
    return 0;
}