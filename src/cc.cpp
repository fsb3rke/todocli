#include "cc.h"


std::vector<std::string> cc::chrToVec(char const *chrArr[], int argc) {
	std::vector<std::string> stackVec;

	for (int i = 0; i < argc; ++i) {
		stackVec.push_back(chrArr[i]);
	}

	return stackVec;
}