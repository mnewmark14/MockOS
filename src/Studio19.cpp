#include <iostream>
#include <vector>
#include <string>
#include "mockos/Constants.h"
#include "mockos/AbstractFile.h"
#include "mockos/TextFile.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

int main() {
    // Creates a textFile to test
    TextFile newText("newText");
    newText.write({'h', 'e', 'l', 'l', 'o'});
    vector<char> readNewText = newText.read();

    // Compares printing out the textFile without visitor and with visitor
    cout << "Without visitor: " << readNewText.data() << endl;
    BasicDisplayVisitor bdv;
    cout << "With visitor: ";
    newText.accept(&bdv);

    // Edits the content of the file
    readNewText[0] = 'y';
    newText.write(readNewText);

    // Compares printing of the edited TextFile
    cout << "Without visitor: " << newText.read().data() << endl;
    cout << "With visitor: ";
    newText.accept(&bdv);

    return SUCCESS;
}