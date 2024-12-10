#include "mockos/BasicDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile *textFile) {
    // Iterates through the textFile parameter and prints out each character
    for (char c: textFile->read()) {
        cout << c;
    }

    cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile *imageFile) {

    // Read the contents of the imageFile into contents
    vector<char> contents = imageFile->read();

    // Calculate the length of one side of the image file
    int n = sqrt(imageFile->getSize());

    // Returns an error if the size of the imageFile is not the same as expected size
    if (n * n != contents.size()) {
        cerr << "Error: invalid size" << endl;
        return;
    }

    // Loops through the imageFile and finds the corresponding index of each coordinate
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {

            int index = imageFile->coordToIndex(x, y);

            // prints the contents of the imageFile one by one
            cout << contents[index];
        }
        cout << endl;
    }
}
