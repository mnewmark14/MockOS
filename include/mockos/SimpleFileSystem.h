#ifndef MOCKOS_SIMPLEFILESYSTEM_H
#define MOCKOS_SIMPLEFILESYSTEM_H

#include <iostream>
#include <map>
#include <set>
#include <string>
#include "AbstractFileSystem.h"

using namespace std;

// Allows the user to maintain a file system
class SimpleFileSystem: public AbstractFileSystem{
private:
    map<string, AbstractFile*> files;
    set<AbstractFile*> openFiles;
public:
    // Adds a file to the file system
    int addFile(string fileName, AbstractFile * file) override;

    // Deletes a file from the file system
    int deleteFile(string fileName) override;

    // Opens a file from the file system
    AbstractFile * openFile(string fileName) override;

    // Closes an open file
    int closeFile(AbstractFile * file) override;

    // Returns the names of the files in the file system
    set<string> getFileNames() override;
};

#endif //MOCKOS_SIMPLEFILESYSTEM_H