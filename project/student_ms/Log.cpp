//
// Created by PC on 2025/10/17.
//

#include <cstdarg>
#include <iostream>

#include "Log.h"
#include "Util.h"

namespace ms {

    void Log::Info(const char* fmt, ...) {
        va_list args;
        va_start(args, fmt);
        std::cout << PrintString(fmt, args) << std::endl;
        va_end(args);
    }

    void Log::Error(const char* fmt, ...) {
        std::cout << ;
        va_list args;
        va_start(args, fmt);
        std::cerr << PrintString(fmt, args) << std::endl;
        va_end(args);
    }

}