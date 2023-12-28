#include "CommandHandlerer.h"


void CommandHandlerer::commandInitialize() {
    if (!fs::exist()) fs::createInitFile();
}

void CommandHandlerer::addTask(std::string task) {
    this->data["app"]["tasks"].push_back({
            {"task", task},
            {"completed", false}
        });

    std::cout << "\"" << task << "\"" << " is " << "\x1B[32m" << "added" << "\033[0m" << "." << std::endl;
    writeToInitFile();
    // std::cout << this->data.dump(4) << std::endl;
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
    json tasks = this->data["app"]["tasks"];
    try
    {
        this->data["app"]["tasks"].erase(id);
    }
    catch(const std::exception& e)
    {
        ERR_IDX_ABT(tasks, (size_t)id, "Array Out of Index.")
    }
    
    std::cout << id << " is " << "\x1B[32m" << "removed" << "\033[0m" << "." << std::endl;
    writeToInitFile();
}

void CommandHandlerer::setTaskStatus(int id, status stat) {
    json tasks = this->data["app"]["tasks"];
    try
    {
        this->data["app"]["tasks"]["id"];
    }
    catch(const std::exception& e)
    {
        ERR_IDX_ABT(tasks, (size_t)id, "Array Out of Index.")
    }

    this->data["app"]["tasks"][id]["completed"] = stat == status::COMPLETED ? true : false;
    std::cout << id << " setted" << (stat == status::COMPLETED ? "\x1B[31m completed" : "\x1B[32m uncompleted") << "\033[0m" << std::endl;
    writeToInitFile();
}

void CommandHandlerer::execute(std::string comm) {
    switch (this->commandMap[comm])
    {
    case INIT:
        this->commandInitialize();
        break;

    // usage: todocli add TASK
    case ADD:
        this->addTask(cc::collectVecInStr(this->argv, 2));
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
        // std::cout << this->argv.at(2) << " " << this->argv.at(3) << std::endl;
        this->setTaskStatus(std::stoi(this->argv.at(3)), this->statusMap[this->argv.at(2)]);
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


void CommandHandlerer::init() {
    std::ifstream f(INIT_FILE);
    this->data = json::parse(f);

    // std::cout << data["app"]["tasks"].dump(4) << std::endl;
}