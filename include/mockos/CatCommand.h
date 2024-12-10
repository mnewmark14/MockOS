#ifndef MOCKOS_CATCOMMAND_H
#define MOCKOS_CATCOMMAND_H

#include <iostream>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

// Child of AbstractCommand, this command allows the user to write to a file
class CatCommand : public AbstractCommand{
public:
    // Constructor
    CatCommand(AbstractFileSystem* fs);

    // Destructor
    ~CatCommand() override = default;

    // Execution of command, allows user to append to the end of a file or overwrite a file
    int execute(string s) override;

    // Displays information on CatCommand to the user
    void displayInfo() override;

private:
    AbstractFileSystem* fs;
};

#endif