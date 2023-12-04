#pragma once

#ifndef COMMAND_HANDLERER_H
#define COMMAND_HANDLERER_H

#include "reqs.h"

enum command {
    INIT,
    ADD,
    LIST,
    NONE
};

class CommandHandlerer {
private:
    void commandInitialize();
    void addTask(std::string task);
    void listTasks();
    json data;
    std::vector<std::string> argv;
public:
    CommandHandlerer(std::vector<std::string> argv) {
        this->argv = std::move(argv);
    }
    command convert(std::string command);
    void init();
    void execute(command comm);
};

#endif // COMMAND_HANDLERER_H