#ifndef MOCKOS_TEXTFILE_H
#define MOCKOS_TEXTFILE_H

#include <iostream>
#include <vector>
#include <string>
#include "AbstractFile.h"

using namespace std;

// Allows the user to create text files
class TextFile : public AbstractFile {
public:
    // Constructor
    TextFile(string newName);

    // Returns the size of the file
    unsigned int getSize() override;

    // Returns the name of the file
    string getName() override;

    // Writes to the file
    int write(vector<char> newVect) override;

    // Appends text to the file
    int append(vector<char> addtlVect) override;

    // Reads the text file (prints it)
    vector<char> read() override;

    // Accepts a visitor to the file
    void accept(AbstractFileVisitor *afv) override;

    // Creates a clone of the file
    AbstractFile *clone(string newName) override;

private:
    string name;
    vector<char> contents;
};

#include "AbstractFileVisitor.h"

#endif //MOCKOS_TEXTFILE_H