#ifndef MOCKOS_TOUCHCOMMAND_H
#define MOCKOS_TOUCHCOMMAND_H

#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

// TouchCommand creates files
class TouchCommand : public AbstractCommand {
public:
    // Constructor
    TouchCommand(AbstractFileSystem* fileSystem, AbstractFileFactory* fileFactory);

    // Destructor
    ~TouchCommand() override = default;

    // Displays info on TouchCommand and its functionality
    void displayInfo() override;

    // Executes TouchCommand, allows the user to create a file
    int execute(string s) override;

private:
    AbstractFileSystem * fileSystem;
    AbstractFileFactory * fileFactory;
};

#endif //MOCKOS_TOUCHCOMMAND_H