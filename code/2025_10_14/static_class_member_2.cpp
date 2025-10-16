//
// Created by PC on 2025/10/16.
//

#include <iostream>
#include <vector>

using std::vector;
using std::string;

class BankAccount {
public:
    explicit BankAccount(string user_name, int value): user_name(std::move(user_name)), value(value) {
        kAccounts.push_back(*this);
    }

    static void PrintAll() {
        for (const auto& a : kAccounts) {
            std::cout << a.user_name << ':' << a.value << '\n';
        }
        std::cout << std::endl;
    }
private:
    static vector<BankAccount> kAccounts;
    string user_name;
    int value;
};

std::vector<BankAccount> BankAccount::kAccounts{};

int main() {
    BankAccount a("A", 12);
    BankAccount b("B", 5);
    BankAccount::PrintAll();
}