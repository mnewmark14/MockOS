#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/Constants.h"
#include <sstream>
#include <string>

using namespace std;

int SimpleFileSystem::addFile(string fileName, AbstractFile *file) {
    // Returns an error if the file name is already in use

    if (files.find(fileName) != files.end()) {
        return FILE_ALREADY_EXISTS;
    }

    // Returns an error if the file is empty
    if (file == nullptr) {
        return FILE_IS_NULL;
    }

    // Inserts a pair of the fileName and file parameters into the files member variable
    pair<string, AbstractFile*> filePair = make_pair(fileName, file);
    files.insert(filePair);

    return SUCCESS;
}

AbstractFile * SimpleFileSystem::openFile(string fileName) {
    // Creates an iterator that determines the location of the parameter fileName in the files member variable
    auto fileIterator = files.find(fileName);

    // Runs if the fileName is in the files member variable
    if (fileIterator != files.end()) {
        AbstractFile * second = fileIterator->second;

        // Checks to see if the file has been opened
        if (openFiles.find(second) == openFiles.end()) {

            // Inserts the file into the openFiles member variable and returns the opened file
            openFiles.insert(second);
            return second;
        }
    }

    // Returns nullptr if the file does not exist or is already open
    return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile * file) {
    // Checks to see if the file is in the openFiles member variable

    if (openFiles.find(file) != openFiles.end()) {

        // Removes the found file from the openFiles member variable
        openFiles.erase(file);
        return SUCCESS;
    } else {
        // Returns an error if the file was not found in openFiles
        return FILE_NOT_OPEN;
    }
}

int SimpleFileSystem::deleteFile(string fileName) {
    auto it = files.find(fileName);

    // Checks to see if the fileName was not found in files
    if (it == files.end()) {
        return FILE_DOES_NOT_EXIST;
    }

    // Checks to see if the file is in openFiles
    if (openFiles.find(it->second) != openFiles.end()) {
        return FILE_IS_OPEN;
    }

    // Removes the file from the list of files if it exists and is closed
    files.erase(it);
    delete it->second;

    return SUCCESS;
}

set<string> SimpleFileSystem::getFileNames() {
    // Creates a set in which to store the fileNames
    set<string> fileNames;

    // Iterates through the list of files and inserts their names into fileNames
    for (const auto& filePair : files) {
        fileNames.insert(filePair.first);
    }

    return fileNames;
}

