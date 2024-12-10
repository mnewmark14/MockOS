#include "mockos/ImageFile.h"
#include "mockos/Constants.h"
#include <cmath>
#include <vector>

// Constructor initializes the name and size member variables
ImageFile::ImageFile(string newName) : name(newName), size(0) {}

unsigned int ImageFile::getSize() {
    // Returns the size member variable
    return size;
}

string ImageFile::getName() {
    // Returns the name member variable
    return name;
}

int ImageFile::write(vector<char> image) {
    // Calculate image size from last char in image parameter
    int imgSize = image.back() - 48;
    image.pop_back();

    // If the size of image parameter is not equivalent to its reported length squared, return an error
    if (image.size() != imgSize * imgSize) {
        return SIZE_MISMATCH;
    }


    for (auto pixel: image) {
        // Throws an error if a pixel is not reported as 'X' or ' '
        if (pixel != 'X' && pixel != ' ') {
            return INVALID_IMAGE;
        }

        // Enters the pixels one by one into the contents member variable
        contents.push_back(pixel);
    }

    // Sets the size member variable to the reported length of the image parameter squared
    size = imgSize * imgSize;

    return SUCCESS;
}

int ImageFile::append(vector<char> newVect) {
    // Returns an error indicating append does not exist for ImageFiles
    return APPEND_NOT_SUPPORTED;
}

int ImageFile::coordToIndex(int x, int y) {
    return y * sqrt(size) + x;
}

vector<char> ImageFile::read() {
//    for (int y = 0; y < sqrt(size); ++y){
//        for (int x = 0; x <  sqrt(size); ++x) {
//            int index = coordToIndex(x, y);
//            cout << contents[index] << " ";
//        }
//        cout << endl;
//    }

    // Returns the contents member variable
    return contents;
}

void ImageFile::accept(AbstractFileVisitor *afv) {
    // Visits this text file with the file visitor
    afv->visit_ImageFile(this);
}

AbstractFile *ImageFile::clone(string newName) {
    // Create a copy of this text file, changes its name to newName and returns it
    auto* newFile = new ImageFile(*this);
    newFile->name = newName + ".img";
    return newFile;
}