//
// Created by stupid_coder_jyy on 25-10-18.
//
#include <iostream>

int main() {
    int arr[]{ 0x64636261, 0x00676665  };
    auto* p = reinterpret_cast<const char*>(arr);
    std::cout << p << std::endl;
}