#include <iostream>
#include <iomanip>
#include <set>
#include <string>
#include "mockos/LSCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/Constants.h"
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;

// Constructor, initializes fileSystem member variable
LSCommand::LSCommand(AbstractFileSystem *fileSystem)
        : fileSystem(fileSystem) {}

// Prints info on LSCommand to the suer
void LSCommand::displayInfo() {
    cout << "ls outputs the names of all files currently in the file system. ls can be invoked with the command: ls "
            "\n ls -m will display the metadata for each file as well." << endl;
}

int LSCommand::execute(string s) {
    // Stores the fileNames in the fileSystem in a set
    set<string> fileNames = fileSystem->getFileNames();

    // Checks if the user inputted the optional "-m"
    if (s.empty()) {
        int count = 0;

        // Iterates through the fileNames
        for (const auto &fileName: fileNames) {

            // Prints out fileNames two at a time
            cout << left << setw(20) << fileName;
            count++;

            // Starts a new line every two files
            if (count % 2 == 0) {
                cout << endl;
            }
        }

        // Ends final line if there are an odd number of file names
        if (count % 2 != 0) {
            cout << endl;
        }
    } else if (s == "-m") {

        // If -m option selected
        MetadataDisplayVisitor mdv;

        // Iterates through all the file names
        for (const string &fileName: fileNames) {

            // Prints the file name and metadata to the user
            AbstractFile *file = fileSystem->openFile(fileName);
            file->accept(&mdv);
            fileSystem->closeFile(file);
        }
    } else {
        cerr << "Error: option not supported for ls command" << endl;
        return COMMAND_FAILED;
    }

    return SUCCESS;
}

