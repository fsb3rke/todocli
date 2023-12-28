#pragma once

#ifndef COMMAND_HANDLERER_H
#define COMMAND_HANDLERER_H

#include "reqs.h"
#include <functional>
#include <unordered_map>


enum command {
    INIT,
    ADD,
    LIST,
    GET,
    REMOVE,
    STATUS,
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
    void addTask(std::string task);
    void listTasks();
    void getTask(int id);
    void removeTask(int id);
    void setTaskStatus(int id, status stat);
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
        {"none", command::NONE}
    };
    std::unordered_map<std::string, status> statusMap {
        {"completed", status::COMPLETED},
        {"uncompleted", status::UNCOMPLETED}
    };
public:
    CommandHandlerer(std::vector<std::string> argv) {
        this->argv = std::move(argv);
    }
    void init();
    void execute(std::string comm);
};

#endif // COMMAND_HANDLERER_H