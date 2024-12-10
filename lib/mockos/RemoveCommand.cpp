#include "mockos/RemoveCommand.h"
#include "mockos/Constants.h"

// Constructor, initializes fileSystem member variable
RemoveCommand::RemoveCommand(AbstractFileSystem *fileSystem)
        : fileSystem(fileSystem) {}

// Prints info on RemoveCommand to the user
void RemoveCommand::displayInfo() {
    cout << "Remove removes a file, remove can be invoked with the command: rm <filename>" << endl;
}

int RemoveCommand::execute(string s) {
    // Attempts to delete inputted file from the fileSystem
    int deletion = fileSystem->deleteFile(s);

    // Reports a failure to the user
    if (deletion != SUCCESS){
        cout << "Deletion was unsuccessful" << endl;
        return DELETION_FAILED;
    }

    return SUCCESS;
}