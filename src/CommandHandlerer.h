#ifndef COMMAND_HANDLERER_H
#define COMMAND_HANDLERER_H

#include "reqs.h"
#include <functional>
#include <unordered_map>
#include <ctime>
#include <tabulate.hpp>


enum command {
    INIT,
    ADD,
    LIST,
    GET,
    REMOVE,
    STATUS,
    HELP,
    NONE
};

#define PARAM_COMPLETE "--c"
#define PARAM_UNCOMPLETE "--u"
enum status {
    COMPLETED,
    UNCOMPLETED
};

class CommandHandlerer {
private:
    void commandInitialize();
    void addTask(const std::string& task);
    void listTasks();
    void getTask(const int& id);
    void removeTask(const int& id);
    void setTaskStatus(const int& id, const status& stat);
    std::function<void()> writeToInitFile = [this]() {
        fs::writeOnInitFile(this->data.dump(4));
    };
    json data;
    std::vector<std::string> argv;
    std::unordered_map<std::string, command> commandMap {
        {"init", command::INIT},
        {"add", command::ADD},
        {"list", command::LIST},
        {"get", command::GET},
        {"remove", command::REMOVE},
        {"status", command::STATUS},
        {"help", command::HELP},
        {"none", command::NONE}
    };
    std::unordered_map<std::string, status> statusMap {
        {PARAM_COMPLETE, status::COMPLETED},
        {PARAM_UNCOMPLETE, status::UNCOMPLETED}
    };
    std::unordered_map<std::string, std::string> helpMap {
        {"init", "creates a todocli init file."},
        {"list", "lists all tasks."},
        {"get INDEX", "get spesific task with index."},
        {"add TASK", "add task."},
        {"remove INDEX", "remove spesific task with index."},
        {"status STATUS INDEX", "change spesific task status with status parameter and index."}
    };
    tabulate::Table cliView;
public:
    CommandHandlerer(const std::vector<std::string>& argv) {
        this->argv = argv;
    }
    void init();
    void execute(const std::string& comm);
};

#endif // COMMAND_HANDLERER_H