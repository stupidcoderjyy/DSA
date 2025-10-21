//
// Created by PC on 2025/10/17.
//

#include <cstdarg>
#include <iostream>
#include <fstream>

#include "Log.h"

#include <chrono>

namespace ms {

    Buf::Buf(std::ofstream& file_out): std_out_(std::cout), file_out_(file_out) {
    }

    int Buf::overflow(int c) {
        if (c != EOF) {
            file_out_.put(static_cast<char>(c));
            std_out_.put(static_cast<char>(c));
        }
        return c;
    }

    std::streamsize Buf::xsputn(const char *s, std::streamsize n) {
        std_out_.write(s, n);
        file_out_.write(s, n);
        return n;
    }

    Log::Log(const std::string &file_path): std::ostream(&buf_),
            file_out_(file_path, std::ios::app), buf_(file_out_) {
        if (!file_out_.is_open()) {
            throw std::runtime_error("Failed to open log file: " + file_path);
        }
    }

    Log::~Log() {
        file_out_.flush();
    }

    Logger::Logger(const std::string &file_path): log_(file_path) {
    }

    std::ostream& Logger::info() {
        PrintTime();
        return log_ << "[info]";
    }

    std::ostream& Logger::error() {
        PrintTime();
        return log_ << "[error]";
    }

    void Logger::PrintTime() {
        using std::chrono::system_clock;
        auto now = system_clock::now();                  // 当前时间点
        std::time_t t = system_clock::to_time_t(now);    // 转换为 time_t
        std::tm tm = *std::localtime(&t);
        log_ << '[' << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << ']';
    }
}
