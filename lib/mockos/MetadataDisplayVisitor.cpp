#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile *text) {
    // Prints the textFile's name and size
    cout << left << setw(20) << text->getName()
         << left << setw(10) << "text"
         << right << setw(3) << text->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile *image) {
    // Prints the imageFile's name and size
    cout << left << setw(20) << image->getName()
         << left << setw(10) << "image"
         << right << setw(3) << image->getSize() << endl;
}

