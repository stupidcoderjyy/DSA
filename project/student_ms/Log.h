//
// Created by PC on 2025/10/17.
//

#ifndef DSA_LOG_H
#define DSA_LOG_H

namespace ms {

    class Log {
    public:
        void Info(const char* format, ...);
        void Error(const char* format, ...);
    };

}


#endif //DSA_LOG_H