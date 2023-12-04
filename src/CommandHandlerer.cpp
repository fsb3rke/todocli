#include "CommandHandlerer.h"


void CommandHandlerer::commandInitialize() {
    if (!fs::exist()) fs::createInitFile();
}

void CommandHandlerer::addTask(std::string task) {
    this->data["app"]["tasks"].push_back({
            {"task", task},
            {"completed", false}
        });

    std::cout << this->data.dump(4) << std::endl;
}

void CommandHandlerer::execute(command comm) {
    switch (comm)
    {
    case INIT:
        this->commandInitialize();
        break;

    case ADD:
        this->addTask(this->argv.at(2));
        break;
    
    default:
        break;
    }
}

command CommandHandlerer::convert(std::string command) {
    if (command == "init") return command::INIT;
    else if (command == "add") return command::ADD;

    return command::NONE;
}

void CommandHandlerer::init() {
    std::ifstream f(INIT_FILE);
    this->data = json::parse(f);

    std::cout << data["app"]["tasks"].dump(4) << std::endl;
}