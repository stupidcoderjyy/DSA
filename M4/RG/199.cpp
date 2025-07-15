//
// Created by PC on 25-7-14.
//

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

bool rg199(const string& ops) {
    int count = 0;
    for (char op : ops) {
        if (op == 'I') {
            count++;
        } else if (count == 0) {
            return false;
        } else {
            count--;
        }
    }
    return count == 0;
}

int main() {
    cout << rg199("IOIIOIOO") << endl;
    cout << rg199("IOOIOIIO") << endl;
    cout << rg199("IIIOIOIO") << endl;
    cout << rg199("IIIOOIOO") << endl;
}