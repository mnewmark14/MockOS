#include <iostream>
#include <vector>
#include <string>
#include "mockos/Constants.h"
#include "mockos/AbstractFile.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileFactory.h"

using namespace std;

int main() {
    // Create an instance of a SimpleFileSystem and SimpleFileFactory
    AbstractFileSystem *afs = new SimpleFileSystem;
    AbstractFileFactory *aff = new SimpleFileFactory;

    // Test the creation of text and image files
    AbstractFile *textFile = aff->createFile("textFile.txt");
    AbstractFile *imageFile = aff->createFile("imageFile.img");

    // Test the addition of text and image files to the file system
    afs->addFile(aff->createFile("textFile.txt")->getName(), textFile);
    afs->addFile(imageFile->getName(), imageFile);

    // Test the opening, writing, and reading of text files from the file system
    AbstractFile *openTextFile = afs->openFile("textFile.txt");
    openTextFile->write({'p', 'r', 'i', 'z', 'e'});
    openTextFile->read();

    // Test the opening, writing, and reading of image files from the file system
    AbstractFile *openImageFile = afs->openFile("imageFile.img");
    openImageFile->write({'X', 'X', ' ', 'X', '2'});
    openImageFile->read();

    // Test the closing of text and image files from the file system
    afs->closeFile(openTextFile);
    afs->closeFile(openImageFile);

    return SUCCESS;
}