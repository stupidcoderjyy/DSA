//
// Created by PC on 2025/10/11.
//

#include <cstdio>
#include <ctime>
#include <iostream>

#define BUFFER_SIZE 10

int main() {
    FILE* f = fopen("log.txt", "a");
    if (!f) {
        perror("Failed to open file");
        return 1;
    }
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
    fprintf(f, "%s\n", buffer);
    fclose(f);
}
