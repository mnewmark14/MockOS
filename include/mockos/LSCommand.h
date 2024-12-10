#ifndef MOCKOS_LSCOMMAND_H
#define MOCKOS_LSCOMMAND_H

#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

// Child of AbstractCommand, displays the names of all files currently in the file system
class LSCommand : public AbstractCommand {
public:
    // Constructor
    LSCommand(AbstractFileSystem* fileSystem);

    // Destructor
    ~LSCommand() override = default;

    // Displays info to the user on LSCommand and its functionality
    void displayInfo() override;

    // Executes the command, displays the names of all files, optional -m displays the names and metadata
    // of all the files in the file system
    int execute(string s) override;

private:
    AbstractFileSystem * fileSystem;
};

#endif //MOCKOS_LSCOMMAND_H