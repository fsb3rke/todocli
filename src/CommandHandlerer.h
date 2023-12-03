#pragma once

#ifndef COMMAND_HANDLERER_H
#define COMMAND_HANDLERER_H

#include "reqs.h"

enum command {
    INIT,
    NONE
};

class CommandHandlerer {
private:
    void commandInitialize();
    json data;
public:
    command convert(std::string command);
    void init();
    void execute(command comm);
};

#endif // COMMAND_HANDLERER_H