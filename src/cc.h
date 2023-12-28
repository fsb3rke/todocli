#pragma once

#ifndef CC_H_
#define CC_H_

#include <string>
#include <vector>

namespace cc {
    std::vector<std::string> chrToVec(char const *chrArr[], int argc);
    std::string collectVecInStr(std::vector<std::string> vec, size_t startIdx);
} // namespace cc

#endif // CC_H_
