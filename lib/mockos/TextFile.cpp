#include <string>
#include <vector>
#include "mockos/TextFile.h"
#include "mockos/Constants.h"

using namespace std;

// Constructor initializes member variable
TextFile::TextFile(string newName) : name(newName) {}


vector<char> TextFile::read() {
//    for (char c : contents) {
//        cout << c;
//    }
//    cout << endl;
    // Returns the contents member variable
    return contents;
}

int TextFile::write(vector<char> newVect) {
    // Updates contents member variable to the a copy of the parameter
    contents = newVect;
    return SUCCESS;
}

int TextFile::append(vector<char> addtlVect) {
    // Adds the addtlVect parameter to the end of the contents member variable
    contents.insert(contents.end(), addtlVect.begin(), addtlVect.end());
    return SUCCESS;

}

unsigned int TextFile::getSize() {
    // Returns the size of the contents member variable
    return contents.size();
}

string TextFile::getName() {
    // Returns the name member variable
    return name;
}

void TextFile::accept(AbstractFileVisitor *afv) {
    // Visits this text file with the file visitor
    afv->visit_TextFile(this);
}

AbstractFile *TextFile::clone(string newName) {
    // Create a copy of this text file, changes its name to newName and returns it
    auto* newFile = new TextFile(*this);
    newFile->name = newName + ".txt";
    return newFile;
}
