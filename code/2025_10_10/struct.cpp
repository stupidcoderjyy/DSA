//
// Created by PC on 2025/10/10.
//

#include <iostream>

struct BookInfo {
    const char* name;
    const char* author;
    int year;
    float price;
};

void print(const BookInfo& info) {
    std::cout << "name:" << info.name << '\n';
    std::cout << "author:" << info.author << '\n';
    std::cout << "year:" << info.year << '\n';
    std::cout << "price:" << info.price << std::endl;
}

int main() {
    std::string name, author;
    int year;
    float price;
    std::cin >> name >> author >> year >> price;
    BookInfo info = {name.c_str(), author.c_str(), year, price};
    print(info);
}
