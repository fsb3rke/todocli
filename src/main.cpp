#include "CommandHandlerer.h"

std::vector<std::string> chrToVec(char const *chrArr[], int argc);

int main(int argc, char const *argv[])
{
	std::vector<std::string> vecArgv = chrToVec(argv, argc);
	CommandHandlerer com(vecArgv);
	std::string command = vecArgv.at(1);

	if (command != "init") com.init();

	com.execute(com.convert(command));

	return 0;
}

std::vector<std::string> chrToVec(char const *chrArr[], int argc) {
	std::vector<std::string> stackVec;

	for (int i = 0; i < argc; ++i) {
		stackVec.push_back(chrArr[i]);
	}

	return stackVec;
}