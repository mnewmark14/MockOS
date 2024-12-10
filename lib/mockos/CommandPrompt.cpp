#include <iostream>
#include <sstream>
#include <string>
#include "mockos/CommandPrompt.h"
#include "mockos/Constants.h"

using namespace std;

// Constructor, initializes fileSystemObject and fileFactoryObject member variables to be nullptrs
CommandPrompt::CommandPrompt() : fileSystemObject(nullptr), fileFactoryObject(nullptr){}

void CommandPrompt::setFileSystem(AbstractFileSystem * system) {
    // Updates fileSystemObject
    fileSystemObject = system;
}

void CommandPrompt::setFileFactory(AbstractFileFactory * factory) {
    // Updates fileFactoryObject
    fileFactoryObject = factory;
}

int CommandPrompt::addCommand(std::string name, AbstractCommand * command) {

    // Pairs the parameter name and command
    pair<string, AbstractCommand *> commandPair = make_pair(name, command);

    // Attempts to insert the pair into the member variable commandObjects
    auto result = commandObjects.insert(commandPair);

    // Returns success if insertion successful,
    if (result.second) {
        return SUCCESS;
    } else {
        return INSERTION_FAILED;
    }
}

void CommandPrompt::listCommands() {
    cout << "Available Commands: ";

    // Lists the names of available commands to users, iterates through commandObjects member variable
    for (const auto& pair : commandObjects) {
        cout << pair.first << " ";
    }

    cout << endl;
}

string CommandPrompt::prompt() {
    // Prompts the user to enter a command, ask for help, or quit
    cout << "Enter a command, q to quit, help for a list of commands, or "
            "help followed by a command name for more information about "
            "that command.\n";

    cout << "$  ";

    // Returns user input
    string input;
    getline(cin, input);
    return input;
}

int CommandPrompt::run() {

    // Runs until an error or success is returned
    while (true) {
        // Captures user input and stores in input
        string input = prompt();

        // Checks if user input equals 'q'
        if (input == "q") {

            // Quits the program and returns a quit message
            cout << "Quitting Program." << endl;
            return USER_QUIT;
        }

        // Checks if user input equals "help"
        else if (input == "help") {

            // Lists available commands
            listCommands();

            // Continues the while loop
            continue;
        }

        // Checks to see if there is no space in the user input
        else if (input.find(' ') == string::npos){

            // Attempts to find the user inputted file name in the commandObjects member variable
            auto found = commandObjects.find(input);

            // Notifies the user if the command name was not found
            if (found == commandObjects.end()) {
                cout << "Command not found" << endl;
            }
            else {
                // Executes the command entered by the user with an empty string argument
                int returnCode = found->second->execute("");

                // Notifies the user if the command failed
                if (returnCode != SUCCESS) {
                    cerr << "This command failed and returned error: " << returnCode << endl;
                }
            }
        }

        // Checks if there is a space in the user input
        else if (input.find(' ')) {
            // Wraps user input into an istringstream and extracts the first word
            istringstream iss(input);
            string first;
            iss >> first;

            // Checks to see if first word is "help"
            if (first == "help") {

                // Extracts second word
                string second;
                iss >> second;

                // Checks to see if the user inputted command is in the commandObjects member variable
                auto it = commandObjects.find(second);

                // Tells the user if the command was not found
                if (it == commandObjects.end()){
                    cout << "Command not found" << endl;
                }

                // Gives user displayInfo on inputted command
                else {
                    it->second->displayInfo();
                }
            }
            else {
                // Checks to see if the first word is in the list of commands
                auto it = commandObjects.find(first);

                // Tells user if not found
                if (it == commandObjects.end()) {
                    cout << "Command not found" << endl;
                }
                else {
                    string restOfInput = input.substr(input.find(' ') + 1);

                    // Executes the inputted command with the user's second word as its string parameter
                    int checkInput = it->second->execute(restOfInput);

                    // Report failure to the user
                    if (checkInput != SUCCESS) {
                        cerr << "This command failed and returned error: " << checkInput << endl;
                    }
                }
            }
        }
    }
}
