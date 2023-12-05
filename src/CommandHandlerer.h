#pragma once

#ifndef COMMAND_HANDLERER_H
#define COMMAND_HANDLERER_H

#include "reqs.h"
#include <functional>

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
public:
    CommandHandlerer(std::vector<std::string> argv) {
        this->argv = std::move(argv);
    }
    command convertCommand(std::string command);
    status convertStatus(std::string param);
    void init();
    void execute(command comm);
};

#endif // COMMAND_HANDLERER_H