//
// Created by PC on 2025/10/21.
//

#include <iostream>
#include <utility>

template<typename Arg>
void Process(Arg&) {
    std::cout << "l value" << std::endl;
}

template<typename Arg>
void Process(Arg&&) {
    std::cout << "r value" << std::endl;
}

template<typename Arg>
void Wrapper(Arg&& arg) {
    Process(std::forward<Arg>(arg));
}

int main() {
    int l = 10;
    int& l_ref = l;
    int&& r_ref = std::move(l_ref);
    //l val
    Process(l);
    Process(l_ref);
    Process(r_ref);
    //r val
    Process(10);
    Process(std::move(r_ref));
}

