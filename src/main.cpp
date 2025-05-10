#include "CommandHandlerer.hpp"
#include "error.hpp"
#include "cc.hpp"


int main(int argc, char const *argv[])
{
	std::vector<std::string> vecArgv = cc::chrToVec(argv, argc);
	ERR_VEC_ABT(vecArgv, "Argument Error.")

	CommandHandlerer com(vecArgv);
	std::string command = vecArgv.at(1);

	if (command != "init") com.init();

	com.execute(command);

	return 0;
}
