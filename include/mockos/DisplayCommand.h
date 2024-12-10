#include <iostream>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

// Child of abstract command, DisplayCommand opens a file and displays its contents, optionally formatted
class DisplayCommand : public AbstractCommand{
public:
    // Constructor
    DisplayCommand(AbstractFileSystem* fs);

    // Destructor
    ~DisplayCommand() override = default;

    // Executes the command, allows the user to open and display a file. The optional -d command will
    // display a file unformatted
    int execute(string s) override;

    // Displays info to the user on DisplayCommand and its functionality
    void displayInfo() override;

private:
    AbstractFileSystem* fs;
};