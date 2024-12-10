#ifndef MOCKOS_ABSTRACTFILE_H
#define MOCKOS_ABSTRACTFILE_H

#include <iostream>
#include <vector>
#include <string>
#include "AbstractFileVisitor.h"

using namespace std;

//base class for all files, several functions that are overridden by children
class AbstractFile {
public:
    virtual vector<char> read() = 0;

    virtual int write(vector<char> writeage) = 0;

    virtual int append(vector<char> appendage) = 0;

    virtual unsigned int getSize() = 0;

    virtual string getName() = 0;

    virtual void accept(AbstractFileVisitor *afv) = 0;

    virtual ~AbstractFile() = default;

    virtual AbstractFile *clone(string newName) = 0;
};

#endif //MOCKOS_ABSTRACTFILE_H