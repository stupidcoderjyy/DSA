//
// Created by PC on 2025/10/6.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int a, b;
    cin >> a >> b;
    // cout << a << " + " << b << " = " << (a + b) << endl;
    // cout << a << " - " << b << " = " << (a - b) << endl;
    // cout << a << " * " << b << " = " << (a * b) << endl;
    // cout << a << " / " << b << " = " << (static_cast<double>(a) / b) << endl;

    //std::endl 效率低
    cout << a << " + " << b << " = " << (a + b) << '\n';
    cout << a << " - " << b << " = " << (a - b) << '\n';
    cout << a << " * " << b << " = " << (a * b) << '\n';
    cout << a << " / " << b << " = " << (static_cast<double>(a) / b) << '\n';
    cout << endl;
}