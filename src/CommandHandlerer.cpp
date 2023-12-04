#include "CommandHandlerer.h"


void CommandHandlerer::commandInitialize() {
    if (!fs::exist()) fs::createInitFile();
}

void CommandHandlerer::addTask(std::string task) {
    this->data["app"]["tasks"].push_back({
            {"task", task},
            {"completed", false}
        });

    fs::writeOnInitFile(this->data.dump(4));
    std::cout << this->data.dump(4) << std::endl;
}

void CommandHandlerer::listTasks() {
    json uData = this->data["app"]["tasks"];
    for (size_t i = 0; i < uData.size(); ++i) {
        json i_uData = uData[i];
        std::cout << i << " " << (i_uData["completed"] ? "\x1B[31m" : "\x1B[32m") << " " << i_uData["task"] << "\033[0m" << std::endl;
    }
}

void CommandHandlerer::getTask(int id) {
    json _data = this->data["app"]["tasks"][id];
    std::cout << id << " " << (_data["completed"] ? "\x1B[31m" : "\x1B[32m") << " " << _data["task"] << "\033[0m" << std::endl;
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

    case LIST:
        this->listTasks();
        break;

    case GET:
        this->getTask(std::stoi(this->argv.at(2)));
        break;
    
    default:
        break;
    }
}

command CommandHandlerer::convert(std::string command) {
    if (command == "init") return command::INIT;
    else if (command == "add") return command::ADD;
    else if (command == "list") return command::LIST;
    else if (command == "get") return command::GET;

    return command::NONE;
}

void CommandHandlerer::init() {
    std::ifstream f(INIT_FILE);
    this->data = json::parse(f);

    std::cout << data["app"]["tasks"].dump(4) << std::endl;
}