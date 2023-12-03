#include "fs.h"

void fs::createInitFile() {
    std::ofstream f(INIT_FILE);
    f << INIT_CONTENT;
    f.close();
}

bool exist() {
    std::ifstream f(INIT_FILE);
    return f.good(); // No memory leak. Because ifstream will called to be destroy at exit.
}