#include <iostream>
#include <sstream>
#include "mockos/CopyCommand.h"
#include "mockos/Constants.h"
#include "mockos/AbstractFile.h"

using namespace std;

// Constructor, initializes fileSystem member variable
CopyCommand::CopyCommand(AbstractFileSystem *fileSystem)
        : fileSystem(fileSystem) {}

int CopyCommand::execute(string s) {
    // Wraps parameter s with istringstream, extracts first two words into fileToCopyName, newName
    istringstream iss(s);
    string fileToCopyName;
    string newName;

    // Verifies user inputted names correctly
    if (!(iss >> fileToCopyName >> newName)) {
        cerr << "Error: option not supported for cp command" << endl;
        return COMMAND_FAILED;
    }

    // Attempts to open file associated with fileToCopy
    AbstractFile *fileToCopy = fileSystem->openFile(fileToCopyName);
    fileSystem->closeFile(fileToCopy);

    // Returns failure if fileToCopy name not associated with any file
    if (fileToCopy == nullptr) {
        cerr << "Error: file to copy does not exist in file system" << endl;
        return FILE_DOES_NOT_EXIST;
    }

    // Declare a pointer for the copied file
    AbstractFile *fileCopy = nullptr;
    try {
        // Clone the file to create a copy with a new name
        fileCopy = fileToCopy->clone(newName);
    } catch (...) {
        // Catch and report any errors
        cerr << "Error making copy of file" << endl;
        return COPY_ERROR;
    }

    // Attempt to add the copied file to the system, return if there is an error
    if (fileSystem->addFile(fileCopy->getName(), fileCopy) != SUCCESS) {
        cerr << "Error adding copy to file system" << endl;
        return FAILED_TO_ADD_FILE_TO_FS;
    }

    return SUCCESS;
}

// Prints info on CopyCommand to the user
void CopyCommand::displayInfo() {
    cout << "cp will copy a file that exists in the file system and add the copy to the file\n"
            "system with a different name. It is invoked with the following command structure:\n"
            "cp <file_to_copy> <new_name_with_no_extension>" << endl;
}