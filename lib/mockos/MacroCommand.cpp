#include <iostream>
#include <sstream>
#include <vector>
#include "mockos/Constants.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/MacroCommand.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

// Constructor, initializes fs and parser member variables
MacroCommand::MacroCommand(AbstractFileSystem* fs) : fs(fs), parser(nullptr){};

int MacroCommand::execute(string s) {
    // Parses s using parser member variable, stores parsedInfo
    vector<string> parsedInfo = parser->parse(s);

    // Returns an error if the number of inputs does not match the number of commands
    if(parsedInfo.size() != commands.size()) {
        cerr << "Error: Number of commands and number of inputs do not match" << endl;
        return COMMAND_INPUT_MISMATCH;
    }

    // Iterates through each command and executes with parameter from corresponding index in parsedInfo
    for (int i = 0; i < commands.size(); ++i) {
        int output = commands[i]->execute(parsedInfo[i]);

        // Returns an error if one occurs
        if (output != SUCCESS) {
            return output;
        }
    }
    return SUCCESS;

}

// Prints info on MacroCommand to the user
void MacroCommand::displayInfo() {
    cout << "MacroCommand constructs commands out of other commands" << endl;
}

// Allows the user to add a command to the commands member variable
void MacroCommand::addCommand(AbstractCommand* addedCommand){
    commands.push_back(addedCommand);
}

// Allows the user to set the parser member variable to a specific parsing strategy
void MacroCommand::setParseStrategy(AbstractParsingStrategy* parseStrategy){
    parser = parseStrategy;
}