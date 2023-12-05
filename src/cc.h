#pragma once

#ifndef CC_H_
#define CC_H_

#include <vector>
#include <string>

namespace cc {
    std::vector<std::string> chrToVec(char const *chrArr[], int argc);
    std::string collectVecInStr(std::vector<std::string> vec, size_t startIdx);
}

#endif // CC_H_