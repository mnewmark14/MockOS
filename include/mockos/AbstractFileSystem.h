#ifndef MOCKOS_ABSTRACTFILESYSTEM_H
#define MOCKOS_ABSTRACTFILESYSTEM_H

#include <iostream>
#include <set>
#include <string>
#include "AbstractFile.h"

using namespace std;

// base class for file systems, which store and manage several files
class AbstractFileSystem {
public:
    virtual int addFile(string fileName, AbstractFile * file) = 0;
    virtual int deleteFile(string fileName) = 0;
    virtual AbstractFile * openFile(string fileName) = 0;
    virtual int closeFile(AbstractFile * file) = 0;
    virtual set<string> getFileNames() = 0;
};

#endif //MOCKOS_ABSTRACTFILESYSTEM_H