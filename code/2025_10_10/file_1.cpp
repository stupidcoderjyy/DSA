//
// Created by PC on 2025/10/11.
//

#include <cstdio>
#include <iostream>

#define BUFFER_SIZE 10

int main() {
    FILE* f = fopen("example.txt", "w");
    if (!f) {
        perror("Failed to open file");
        return 1;
    }
    fprintf(f, "%s", "Hello World");
    fclose(f);

    f = fopen("example.txt", "r");
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, f)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, stdout);
    }
    if (ferror(f)) {
        perror("Failed to read file");
    }
    fclose(f);
}
