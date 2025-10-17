//
// Created by PC on 2025/10/17.
//

#include <cstdarg>

#include "Util.h"

std::string PrintString(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    auto result = PrintString(fmt, args);
    va_end(args);
    return result;
}

std::string PrintString(const char *fmt, va_list args) {
    int size = std::vsnprintf(nullptr, 0, fmt, args);
    if (size <= 0) {
        return "";
    }
    std::string result;
    result.resize(size + 1); // +1 为 '\0'
    std::vsnprintf(result.data(), result.size(), fmt, args);
    result.pop_back(); // 去掉最后的 '\0'
    return result;
}
