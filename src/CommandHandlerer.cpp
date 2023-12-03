#include "CommandHandlerer.h"


void CommandHandlerer::commandInitialize() {
    if (!fs::exist()) fs::createInitFile();
}

void CommandHandlerer::execute(command comm) {
    switch (comm)
    {
    case INIT:
        this->commandInitialize();
        break;
    
    default:
        break;
    }
}

command CommandHandlerer::convert(std::string command) {
    if (command == "init") return command::INIT;

    return command::NONE;
}

void CommandHandlerer::init() {
    std::ifstream f(INIT_FILE);
    this->data = json::parse(f);

    std::cout << data.dump(4) << std::endl;
}