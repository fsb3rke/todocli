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

void CommandHandlerer::removeTask(int id) {
    this->data["app"]["tasks"].erase(id);
    fs::writeOnInitFile(this->data.dump(4));
}

void CommandHandlerer::setTaskStatus(int id, status stat) {
    this->data["app"]["tasks"][id]["completed"] = stat == status::COMPLETED ? true : false;
    fs::writeOnInitFile(this->data.dump(4));
}

void CommandHandlerer::execute(command comm) {
    switch (comm)
    {
    case INIT:
        this->commandInitialize();
        break;

    // usage: todocli add TASK
    case ADD:
        this->addTask(this->argv.at(2)); // TODO: collect all args from at second index to last index.
        break;

    // usage: todocli list
    case LIST:
        this->listTasks();
        break;

    // usage: todocli get INDEX
    case GET:
        this->getTask(std::stoi(this->argv.at(2)));
        break;

    // usage: todocli remove INDEX
    case REMOVE:
        this->removeTask(std::stoi(this->argv.at(2)));
        break;
    
    // usage: todocli status --c / --u INDEX
    case STATUS:
        std::cout << this->argv.at(2) << " " << this->argv.at(3) << std::endl;
        this->setTaskStatus(std::stoi(this->argv.at(3)), this->convertStatus(this->argv.at(2)));
        break;

    default:
        // HELP
        std::cout
            << "\tCOMMAND\t\t\t-\tDESCRIPTION"
            << "\n"
            << "\tinit\t\t\t:\tcreates a todocli init file."
            << "\n"
            << "\tlist\t\t\t:\tlists all tasks."
            << "\n"
            << "\tget INDEX\t\t:\tget spesific task with index."
            << "\n"
            << "\tadd TASK\t\t:\tadd task."
            << "\n"
            << "\tremove INDEX\t\t:\tremove spesific task with index."
            << "\n"
            << "\tstatus STATUS INDEX\t:\tchange spesific task status with status parameter and index."
            << std::endl;
        break;
    }
}

command CommandHandlerer::convertCommand(std::string command) {
    if (command == "init") return command::INIT;
    else if (command == "add") return command::ADD;
    else if (command == "list") return command::LIST;
    else if (command == "get") return command::GET;
    else if (command == "remove") return command::REMOVE;
    else if (command == "status") return command::STATUS;

    return command::NONE;
}

status CommandHandlerer::convertStatus(std::string param) {
    if (param == PARAM_COMPLETE) return status::COMPLETED;
    else if (param == PARAM_UNCOMPLETE) return status::UNCOMPLETED;

    return status::UNCOMPLETED;
}

void CommandHandlerer::init() {
    std::ifstream f(INIT_FILE);
    this->data = json::parse(f);

    std::cout << data["app"]["tasks"].dump(4) << std::endl;
}