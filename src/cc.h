#ifndef CC_H_
#define CC_H_

#include <string>
#include <vector>

namespace cc {
    std::vector<std::string> chrToVec(char const *chrArr[], const int& argc);
    std::string collectVecInStr(const std::vector<std::string>& vec, const size_t& startIdx);
} // namespace cc

#endif // CC_H_
