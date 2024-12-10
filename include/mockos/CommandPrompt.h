#ifndef MOCKOS_COMMANDPROMPT_H
#define MOCKOS_COMMANDPROMPT_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractFileFactory.h"

using namespace std;

// Handles user input, allows users to input commands to interface with file system
class CommandPrompt{
public:
    // Constructor
    CommandPrompt();

    // Updates the file system member variable
    void setFileSystem(AbstractFileSystem * system);

    // Updates the file factory member variable
    void setFileFactory(AbstractFileFactory * factory);

    // Adds a command to the map of commands stored in commandObjects
    int addCommand(string name, AbstractCommand * command);

    // Asks the user to repeatedly input their commands
    int run();

protected:
    // Lists all available commands to the user
    void listCommands();

    // Prompts the user to input their command
    string prompt();

private:
    // Stores the list of available commands
    map<string, AbstractCommand *> commandObjects;

    AbstractFileSystem * fileSystemObject;
    AbstractFileFactory * fileFactoryObject;
};

#endif //MOCKOS_COMMANDPROMPT_H