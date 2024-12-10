#ifndef MOCKOS_IMAGEFILE_H
#define MOCKOS_IMAGEFILE_H

#include <iostream>
#include <string>
#include "AbstractFile.h"

using namespace std;

// Child of AbstractFile, allows the user to create image files
class ImageFile : public AbstractFile {
private:
    string name;
    vector<char> contents;
    char size;

public:
    // Constructor, instantiates the name of the file
    ImageFile(string newName);

    // Returns the size of the contents member variable
    unsigned int getSize() override;

    // Returns the name member variable
    string getName() override;

    // Allows the user to write the ImageFile
    int write(vector<char> image) override;

    // Returns a code indicating append is not supported
    int append(vector<char> newVect) override;

    // Reads the ImageFile, prints to the user
    vector<char> read() override;

    // Converts inputted coordinates to an index in the contents member variable
    int coordToIndex(int x, int y);

    // Accepts a file visitor
    void accept(AbstractFileVisitor *afv) override;

    // Clones the ImageFile into a new ImageFile
    AbstractFile *clone(string newName) override;
};

#include "AbstractFileVisitor.h"

#endif //MOCKOS_IMAGEFILE_H