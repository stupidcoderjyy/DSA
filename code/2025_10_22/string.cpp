//
// Created by PC on 2025/10/23.
//

#include <iostream>
#include <ostream>
#include <string>

int main() {
    std::string s = "abc";
    s.append("d");
    std::cout << s << std::endl;
    s.insert(s.find('b'), "b");
    std::cout << s << std::endl;
    s.erase(s.find('b'), 1);
    std::cout << s << std::endl;
    s.replace(s.find('d'), 1, "e");
    std::cout << s << std::endl;

    const char* s1 = "abcde";
    s = std::string(s1);
    std::cout << s << std::endl;
    //在字符串被修改内容、被销毁、被移动后，返回的指针失效
    std::cout << s.c_str() << std::endl;
}


