//
// Created by PC on 2025/10/17.
//

#ifndef DSA_LOG_H
#define DSA_LOG_H

#include <iostream>
#include <fstream>

namespace ms {

    class Buf : public std::streambuf {
    public:
        explicit Buf(std::ofstream& file_path);
    protected:
        int overflow(int c) override;
        std::streamsize xsputn(const char* s, std::streamsize n) override;
    private:
        std::ostream* std_out_;
        std::ofstream& file_out_;
    };

    class Log : public std::ostream {
    public:
        explicit Log(const std::string& file_path);
        ~Log() override;
    private:
        std::ofstream file_out_;
        Buf buf_;
    };

    class Logger {
    public:
        explicit Logger(const std::string& file_path);
        std::ostream& Info();
        std::ostream& Error();
        std::ostream& PlainText();
    private:
        Log log_;
        void PrintTime();
    };

}


#endif //DSA_LOG_H