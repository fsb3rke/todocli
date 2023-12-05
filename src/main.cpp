#include "CommandHandlerer.h"
#include "cc.h"


int main(int argc, char const *argv[])
{
	std::vector<std::string> vecArgv = cc::chrToVec(argv, argc);
	CommandHandlerer com(vecArgv);
	std::string command = vecArgv.at(1);

	if (command != "init") com.init();

	com.execute(com.convertCommand(command));

	return 0;
}
