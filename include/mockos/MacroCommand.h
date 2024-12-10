#ifndef MOCKOS_MACROCOMMAND_H
#define MOCKOS_MACROCOMMAND_H

#include <iostream>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractParsingStrategy.h"

using namespace std;

// Child of AbstractCommand, this command allows for the use of creating commands out of other commands
// Enables multiple commands to be executed consecutively
class MacroCommand : public AbstractCommand {
public:
    // Constructor
    MacroCommand(AbstractFileSystem* fs);

    //Destructor
    ~MacroCommand() override = default;

    // Executes the command, parses the user input to match input with specific commands
    int execute(string s) override;

    // Displays info on MacroCommand and its functionality
    void displayInfo() override;

    // Adds a command to the list of commands
    void addCommand(AbstractCommand* );

    // Updates the parser member variable
    void setParseStrategy(AbstractParsingStrategy* );


private:
    vector<AbstractCommand* > commands;

    AbstractParsingStrategy* parser;

    AbstractFileSystem* fs;
};

#endif