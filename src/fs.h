#pragma once

#ifndef FS_H_
#define FS_H_

#include <fstream>
#include <string>

#define INIT_FILE "todocli.json"
#define INIT_CONTENT "{\"app\":{\"tasks\":[]}}"

namespace fs {
    void createInitFile();
}

#endif