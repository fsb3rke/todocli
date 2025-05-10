#ifndef FS_H_
#define FS_H_

#include <string>

constexpr const char* INIT_FILE = "todocli.json";
constexpr const char* INIT_CONTENT = "{\"app\":{\"tasks\":[]}}";

namespace fs {
    void createInitFile();
    void writeOnInitFile(const std::string& dumpedContent);
    bool exist();
}

#endif // FS_H_
