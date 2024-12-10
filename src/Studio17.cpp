#include <iostream>
#include <vector>
#include <string>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/Constants.h"
#include "mockos/SimpleFileSystem.h"

using namespace std;

int main () {

    cout << "Call methods by derived class" << endl;

    // Create an image file by derived class and test vectors
    ImageFile imageFile1("test1");
    vector<char> test1 = {'X', 'X', ' ', 'X', '2'};
    vector<char> test2 = {'0'};
    vector<char> test3 = {'X', 'O', 'X', ' ', '2'};

    // Run various tests on imageFile by derived class
    imageFile1.write(test1);
    imageFile1.read();

    // Ensures append operation is not supported
    if (imageFile1.append(test2) != SUCCESS) {
        cout << "Append operation not supported" << endl;
    }
    cout << imageFile1.getSize() << endl;
    cout << imageFile1.getName() << endl;
    ImageFile imageFile2("test2");
    imageFile2.write(test2);
    cout << imageFile2.getSize() << endl;
    cout << imageFile2.getName() << endl;
    ImageFile imageFile3("test3");
    if (imageFile3.write(test3) != SUCCESS) {
        cout << "Failed to write inputted image" << endl;
    }

    cout << endl;
    cout << "Call methods by aliased abstract class" << endl;

    // Create an imageFile by aliased abstract class
    AbstractFile* p1;
    p1 = &imageFile1;

    // Run various tests on imageFile by aliased abstract class
    p1->read();
    if (p1->append(test2) != SUCCESS) {
        cout << "Append operation not supported" << endl;
    }
    cout << p1->getSize() << endl;
    cout << p1->getName() << endl;
    AbstractFile* p2;
    p2 = &imageFile2;
    cout << p2->getSize() << endl;
    cout << p2->getName() << endl;
    AbstractFile* p3;
    p3 = &imageFile3;
    if (p3->write(test3) != SUCCESS) {
        cout << "Failed to write inputted image" << endl;
    }

    cout << endl;
    cout << "SimpleFileSystem tests" << endl;

    // Tests on SimpleFileSystem
    SimpleFileSystem sfs;
    TextFile textFile("test");
    sfs.addFile(textFile.getName(), &textFile);
    sfs.addFile(imageFile1.getName(), &imageFile1);
    sfs.createFile("testImage.img");
    sfs.createFile("testText.txt");
    AbstractFile* open1 = sfs.openFile(textFile.getName());
    vector<char> t = {'p', 'r', 'i', 'z', 'e'};
    open1->write(t);
    open1->read();
    sfs.closeFile(open1);
    sfs.deleteFile(textFile.getName());
    return SUCCESS;
}