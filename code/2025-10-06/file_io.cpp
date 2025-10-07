//
// Created by PC on 2025/10/6.
//

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file_in("in.txt");
    if (!file_in) {
        std::cerr << "Failed to open in.txt" << std::endl;
        return 1;
    }
    std::string line;
    int sum = 0, count = 0;
    while (std::getline(file_in, line)) {
        sum += std::stoi(line);
        count++;
    }
    file_in.close();
    std::ofstream file_out("out.txt");
    file_out << static_cast<double>(sum) / count;
    file_out.close();
}
