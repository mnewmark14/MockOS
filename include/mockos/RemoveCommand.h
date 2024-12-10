#ifndef MOCKOS_REMOVECOMMAND_H
#define MOCKOS_REMOVECOMMAND_H

#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

// RemoveCommand removes a file from the file system
class RemoveCommand : public AbstractCommand {
public:
    // Constructor
    RemoveCommand(AbstractFileSystem* fileSystem);

    // Destructor
    ~RemoveCommand() override = default;

    // Displays info on RemoveCommand and its functionality
    void displayInfo() override;

    // Executes RemoveCommand, removes the user inputted file from the file system
    int execute(string s) override;

private:
    AbstractFileSystem * fileSystem;
};

#endif //MOCKOS_REMOVECOMMAND_H