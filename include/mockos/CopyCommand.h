#ifndef MOCKOS_COPYCOMMAND_H
#define MOCKOS_COPYCOMMAND_H

#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

// Child of AbstractCommand, this command allows the user to copy a file and add it into the system
// with a different name
class CopyCommand : public AbstractCommand {
public:
    // Constructor
    CopyCommand(AbstractFileSystem* fileSystem);

    // Destructor
    ~CopyCommand() override = default;

    // Displays info to the user on CopyCommand
    void displayInfo() override;

    // Execution of command, allows user to copy a file, rename the copy, and add it to the file system
    int execute(string s) override;

private:
    AbstractFileSystem * fileSystem;
};

#endif //MOCKOS_COPYCOMMAND_H