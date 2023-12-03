#include "CommandHandlerer.h"


int main(int argc, char const *argv[])
{
	CommandHandlerer com;
	std::string command = argv[1];

	if (command != "init") com.init();

	com.execute(com.convert(command));

	return 0;
}
