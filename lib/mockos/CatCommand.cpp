#include <iostream>
#include <sstream>
#include "mockos/Constants.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/CatCommand.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

// Constructor, initializes fs member variable
CatCommand::CatCommand(AbstractFileSystem *fs) : fs(fs) {}

int CatCommand::execute(string s){
    // Wraps parameter s into istringstream
    istringstream command(s);
    string fileName;
    string appendage;

    // Extracts first two words of s into fileName and appendage
    command >> fileName >> appendage;

    // Attempts to open file associated with fileName
    AbstractFile* file = fs->openFile(fileName);
    fs->closeFile(file);

    // Returns error if the fileName is not associated with a file
    if (file == nullptr) {
        cerr << "Error: This file does not exist" << endl;
        return FILE_DOES_NOT_EXIST;
    }
    // Checks for user inputted "-a" option
    if (appendage == "-a") {
        // Displays contents of the file to the user
        BasicDisplayVisitor BDVisitor;
        file->accept(&BDVisitor);
        cout << endl;
    }

    // read in the input from the User
    string input;
    string userInput;
    while (getline(cin, input)) {
        // Breaks the while loop
        if (input == ":wq") {
            break;
        }

        // Closes the file if user input ":q"
        else if (input == ":q") {
            fs->closeFile(file);
            return SUCCESS;
        }

        // Adds the additional user input to the file
        userInput += input;
        userInput += '\n';
    }

    // getting rid of the last new line added to the read-in input
    if(userInput.back() == '\n' && !userInput.empty()) {
        userInput.pop_back();
    }

    // Convert user input into vector of chars
    vector<char> inputUser(userInput.begin(), userInput.end());
    int output = SUCCESS;

    // Appends user input to the end of the file if "-a" added, overwrites if not
    if (appendage == "-a") {
        output = file->append(inputUser);
    }
    else {
        output = file->write(inputUser);
    }

    // Closes the file
    fs->closeFile(file);
    return output;
}

// Prints info on CatCommand to the user
void CatCommand::displayInfo() {
    cout << "cat both displays and then appends content to a file. Usage: cat <fileName> [-a]" << endl;
}