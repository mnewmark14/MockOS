#include <iostream>
#include <sstream>
#include "mockos/Constants.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/DisplayCommand.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

// Constructor, initializes fs member variable
DisplayCommand::DisplayCommand(AbstractFileSystem *fs) : fs(fs) {}

int DisplayCommand::execute(string s) {
    // Wrap parameter s in istringstream, extract first two words into fileName and appendage
    istringstream command(s);
    string fileName;
    string appendage;
    command >> fileName >> appendage;

    // Attempt to open file associated with fileName, return failure if no such file
    AbstractFile* file = fs->openFile(fileName);
    if (file == nullptr) {
        cerr << "Error: This file does not exist" << endl;
        return FILE_DOES_NOT_EXIST;
    }

    // reads in files info, and then displays the files contents
    if (appendage == "-d") {
        // Reads the file into a vector
        vector<char> fileInfo = file->read();

        // Prints contents of the file to the user
        for (int i = 0; i < fileInfo.size(); i ++) {
            cout << fileInfo[i];
        }
        cout << endl;

        // Closes file
        fs->closeFile(file);
        return SUCCESS;
    }
    else {
        // Displays the contents of the file formatted using BasicDisplayVisitor
        AbstractFileVisitor* BDVisitor = new BasicDisplayVisitor;
        file->accept(BDVisitor);
    }
    // close the file after execute finished
    fs->closeFile(file);
    return SUCCESS;
}

// Prints info on DisplayCommand to the user
void DisplayCommand::displayInfo() {
    cout << "ds opens a file and displays its contents. Usage: ds <fileName> [-d]" << endl;
}