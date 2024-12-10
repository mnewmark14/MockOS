#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/Constants.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <sstream>


using namespace std;

AbstractFile * SimpleFileFactory::createFile(string fileName) {
    // Wraps fileName in an istringStream
    istringstream iss(fileName);

    // Extracts the part of fileName before the '.' and after the '.'
    string fileExt;
    getline(iss, fileExt, '.');
    getline(iss, fileExt);

    // Declares a pointer to an abstract file
    AbstractFile *file;

    // Determines if the file is a textFile or imageFile (or none), and creates the corressponding file object
    if (fileExt == "txt") {
        file = new TextFile(fileName);
    } else if (fileExt == "img") {
        file = new ImageFile(fileName);
    } else {
        file = nullptr;
    }

    // Returns the pointer to the created file object
    return file;
}