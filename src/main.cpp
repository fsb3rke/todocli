#include "CommandHandlerer.h"
#include "error.h"


int main(int argc, char const *argv[])
{
	std::vector<std::string> vecArgv = cc::chrToVec(argv, argc);
	ERR_ARR_ABT(vecArgv, "Argument Error.")

	CommandHandlerer com(vecArgv);
	std::string command = vecArgv.at(1);

	if (command != "init") com.init();

	com.execute(com.convertCommand(command));

	return 0;
}
