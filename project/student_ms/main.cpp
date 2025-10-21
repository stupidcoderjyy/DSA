//
// Created by PC on 2025/10/17.
//

#include "Log.h"


int main() {
    {
        ms::Logger log("test_log.txt");
        log.info() << "deaws" << std::endl;
    }
}
