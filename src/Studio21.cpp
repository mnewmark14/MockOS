#include <iostream>
#include "mockos/CommandPrompt.h"
#include "mockos/Constants.h"
#include "mockos/TouchCommand.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/AbstractFile.h"

using namespace std;

int main() {
    // Create file system, file factory, and touch objects
    AbstractFileSystem * simpleSystem = new SimpleFileSystem();
    AbstractFileFactory * simpleFactory = new SimpleFileFactory();
    AbstractCommand * touch = new TouchCommand(simpleSystem, simpleFactory);

    // Create command prompt object, initialize member variables, add touch command
    CommandPrompt commandPrompt;
    commandPrompt.setFileSystem(simpleSystem);
    commandPrompt.setFileFactory(simpleFactory);
    commandPrompt.addCommand("touch", touch);

    // Run command prompt and test user input
    commandPrompt.run();

    // Try to open the file created by touch
    AbstractFile * file = simpleSystem->openFile("file.txt");

    // Print success if the file opened successfully
    if (file != nullptr) {
        cout << "File successfully opened" << endl;
    }

    return SUCCESS;
}