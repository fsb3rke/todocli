#include "cc.h"


std::vector<std::string> cc::chrToVec(char const *chrArr[], int argc) {
	std::vector<std::string> stackVec;

	for (int i = 0; i < argc; ++i) {
		stackVec.push_back(chrArr[i]);
	}

	return stackVec;
}

std::string cc::collectVecInStr(std::vector<std::string> vec, size_t startIdx) {
	std::string stackStr;

	for (size_t i = startIdx; i < vec.size(); ++i) {
		stackStr += vec.at(i) + " ";
	}

	stackStr.pop_back();
	return stackStr;
}