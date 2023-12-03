#include "fs.h"

void fs::createInitFile() {
    std::ofstream f(INIT_FILE);
    f << INIT_CONTENT;
    f.close();
}