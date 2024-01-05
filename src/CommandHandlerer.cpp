#include "CommandHandlerer.h"


void CommandHandlerer::commandInitialize() {
    if (!fs::exist()) fs::createInitFile();
}

void CommandHandlerer::addTask(std::string task) {
    time_t now = time(0);
    char* dt = ctime(&now);

    this->data["app"]["tasks"].push_back({
            {"task", task},
            {"completed", false},
            {"date", dt}
        });

    this->cliView.add_row({"ID", "TASK", "DATE"});

    std::stringstream ss;
    int _size = this->data["app"]["tasks"].size();
    ss << (_size-1);
    this->cliView.add_row({ss.str(), task, dt});
    this->cliView[1][1].format().font_color(tabulate::Color::green);
    this->cliView[1][2].format().font_color(tabulate::Color::yellow);

    for (size_t i = 0; i < 3; ++i) {
        this->cliView[0][i].format().font_color(tabulate::Color::magenta).font_align(tabulate::FontAlign::center);
    } 
    std::cout << this->cliView << std::endl;

    // std::cout << "\"" << task << "\"" << " is " << "\x1B[32m" << "added" << "\033[0m" << "." << std::endl;
    writeToInitFile();

    // std::cout << this->data.dump(4) << std::endl;
}

void CommandHandlerer::listTasks() {
    json uData = this->data["app"]["tasks"];
    this->cliView.add_row({"ID", "TASK", "DATE"});

    for (size_t i = 0; i < uData.size(); ++i) {
        json i_uData = uData[i];
        std::stringstream ss;
        ss << i;
        try {
            this->cliView.add_row({ss.str(), (std::string)i_uData["task"], (std::string)i_uData["date"]});
            this->cliView[i+1][1].format().font_color(i_uData["completed"] ? tabulate::Color::red : tabulate::Color::green);
            this->cliView[i+1][2].format().font_color(tabulate::Color::yellow);
        } catch(const std::exception& e) {}
        // std::cout << i << " " << (i_uData["completed"] ? "\x1B[31m" : "\x1B[32m") << " " << i_uData["task"] << " \x1B[33m" << i_uData["date"] << "\033[0m" << std::endl;
    }

    for (size_t j = 0; j < 3; ++j) {
        this->cliView[0][j].format().font_color(tabulate::Color::magenta).font_align(tabulate::FontAlign::center);
    }

    std::cout << this->cliView << std::endl;
}

void CommandHandlerer::getTask(int id) {
    json _data = this->data["app"]["tasks"][id];

    this->cliView.add_row({"ID", "TASK", "DATE"});

    std::stringstream ss;
    ss << id;
    this->cliView.add_row({ss.str(), (std::string)_data["task"], (std::string)_data["date"]});
    this->cliView[1][1].format().font_color(_data["completed"] ? tabulate::Color::red : tabulate::Color::green);
    this->cliView[1][2].format().font_color(tabulate::Color::yellow);

    for (size_t i = 0; i < 3; ++i) {
        this->cliView[0][i].format().font_color(tabulate::Color::magenta).font_align(tabulate::FontAlign::center);
    } 
    std::cout << this->cliView << std::endl;

    // std::cout << id << " " << (_data["completed"] ? "\x1B[31m" : "\x1B[32m") << " " << _data["task"] << " \x1B[33m" << _data["date"] << "\033[0m" << std::endl;
}

void CommandHandlerer::removeTask(int id) {
    json tasks = this->data["app"]["tasks"];

    this->cliView.add_row({"ID", "TASK", "DATE"});

    std::stringstream ss;
    ss << id;
    this->cliView.add_row({ss.str(), (std::string)this->data["app"]["tasks"][id]["task"], (std::string)this->data["app"]["tasks"][id]["date"]});
    this->cliView[1][1].format().font_color(tabulate::Color::red);
    this->cliView[1][2].format().font_color(tabulate::Color::yellow);

    for (size_t i = 0; i < 3; ++i) {
        this->cliView[0][i].format().font_color(tabulate::Color::magenta).font_align(tabulate::FontAlign::center);
    } 
    
    try
    {
        this->data["app"]["tasks"].erase(id);
    }
    catch(const std::exception& e)
    {
        ERR_IDX_ABT(tasks, (size_t)id, "Array Out of Index.")
    }

    std::cout << this->cliView << std::endl;


    // std::cout << id << " is " << "\x1B[32m" << "removed" << "\033[0m" << "." << std::endl;
    writeToInitFile();
}

void CommandHandlerer::setTaskStatus(int id, status stat) {
    json tasks = this->data["app"]["tasks"];
    try
    {
        this->data["app"]["tasks"][id];
    }
    catch(const std::exception& e)
    {
        ERR_IDX_ABT(tasks, (size_t)id, "Array Out of Index.")
    }

    this->data["app"]["tasks"][id]["completed"] = stat == status::COMPLETED;
    this->cliView.add_row({"ID", "TASK", "STATUS", "DATE"});

    std::stringstream ss;
    ss << id;
    this->cliView.add_row({ss.str(), (std::string)this->data["app"]["tasks"][id]["task"], this->data["app"]["tasks"][id]["completed"] ? "Completed" : "UnCompleted", (std::string)this->data["app"]["tasks"][id]["date"]});
    for (int i = 1; i < 3; ++i) {
        this->cliView[1][i].format().font_color(this->data["app"]["tasks"][id]["completed"] ? tabulate::Color::red : tabulate::Color::green);
    }
    this->cliView[1][3].format().font_color(tabulate::Color::yellow);
    for (size_t i = 0; i < 4; ++i) {
        this->cliView[0][i].format().font_color(tabulate::Color::magenta).font_align(tabulate::FontAlign::center);
    } 
    std::cout << this->cliView << std::endl;

    // std::cout << id << " set" << (stat == status::COMPLETED ? "\x1B[31m completed" : "\x1B[32m uncompleted") << "\033[0m" << std::endl;
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

    case HELP:
        // HELP
        // std::cout
        //     << "\tCOMMAND\t\t\t-\tDESCRIPTION"
        //     << "\n"
        //     << "\tinit\t\t\t:\tcreates a todocli init file."
        //     << "\n"
        //     << "\tlist\t\t\t:\tlists all tasks."
        //     << "\n"
        //     << "\tget INDEX\t\t:\tget spesific task with index."
        //     << "\n"
        //     << "\tadd TASK\t\t:\tadd task."
        //     << "\n"
        //     << "\tremove INDEX\t\t:\tremove spesific task with index."
        //     << "\n"
        //     << "\tstatus STATUS INDEX\t:\tchange spesific task status with status parameter and index."
        //     << std::endl;

        this->cliView.add_row({"COMMAND", "DESCRIPTION"});
        this->cliView.add_row({"init", "creates a todocli init file."});
        this->cliView.add_row({"list", "lists all tasks."});
        this->cliView.add_row({"get INDEX", "get spesific task with index."});
        this->cliView.add_row({"add TASK", "add task."});
        this->cliView.add_row({"remove INDEX", "remove spesific task with index."});
        this->cliView.add_row({"status STATUS INDEX", "change spesific task status with status parameter and index."});

        this->cliView.column(0).format().font_color(tabulate::Color::green);

        for (size_t i = 0; i < 2; ++i) {
            this->cliView[0][i].format().font_color(tabulate::Color::magenta).font_align(tabulate::FontAlign::center);
        }

        std::cout << this->cliView << std::endl;
        break;

    default:
        break;
    }
}


void CommandHandlerer::init() {
    std::ifstream f(INIT_FILE);
    this->data = json::parse(f);

    // std::cout << data["app"]["tasks"].dump(4) << std::endl;
}
