//
// Created by PC on 2025/10/7.
//

#include <algorithm>
#include <iostream>

int gcd(int a, int b) {
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    while (true) {
        int a, b;
        std::cin >> a >> b;
        std::cout << gcd(a, b) << std::endl;
        if (a == 0 && b == 0) {
            break;
        }
    }
}