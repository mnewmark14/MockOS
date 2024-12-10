#include <iostream>
#include <sstream>
#include <string>
#include "mockos/TouchCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/Constants.h"
#include "mockos/PasswordProxy.h"

using namespace std;

// Constructor, initializes fileSystem and fileFactory member variables
TouchCommand::TouchCommand(AbstractFileSystem *fileSystem, AbstractFileFactory *fileFactory)
        : fileSystem(fileSystem), fileFactory(fileFactory) {}

// Shares info on touch with the user
void TouchCommand::displayInfo() {
    cout << "touch creates a file. touch can be invoked with the command: touch <filename> \n touch <filename> -p "
            "will create a password protected file and prompt you to make your password." <<
         endl;
}

int TouchCommand::execute(string s) {
    // Wraps parameter s in an istringstream and extracts the file name and second word
    istringstream iss(s);
    string fileName;
    string option;

    iss >> fileName;
    iss >> option;

    // Creates the file with the fileFactory member variable
    AbstractFile *file = fileFactory->createFile(fileName);

    // If created file is null returns an error
    if (file == nullptr) {
        cerr << "Error: Failed creating a new file." << endl;
        return FAILED_TO_CREATE_FILE;
    }

    // Creates a pointer to the created file
    AbstractFile *fileToAdd = file;

    // Checks to see if "-p" was added to end of user input
    if (option == "-p") {

        // Requests the password and extracts from user input
        cout << "What is the password?" << endl;
        string password;
        getline(cin, password);

        // Verifies that password was entered correctly
        AbstractFile *proxy = new PasswordProxy(file, password);
        fileToAdd = proxy;
    } else if (!option.empty()) {
        // Deletes file and returns error if the second word of user input is not "-p"
        delete file;
        cerr << "Error: option not supported for touch command" << endl;
        return COMMAND_FAILED;
    }

    // Alerts the user if there was a failure adding the file to the fileSystem member variable
    if (fileSystem->addFile(fileName, fileToAdd) != SUCCESS) {
        cerr << "Error: Failed to add the new file to the file system." << endl;
        return FAILED_TO_ADD_FILE_TO_FS;
    }

    return SUCCESS;
}
