#ifndef MOCKOS_ABSTRACTPARSINGSTRATEGY_H
#define MOCKOS_ABSTRACTPARSINGSTRATEGY_H
#include <iostream>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

// Base class for parsing strategies, which parse user input and sort it for specific commands
class AbstractParsingStrategy {
public:
    virtual vector<string> parse(string s) = 0;
};

#endif