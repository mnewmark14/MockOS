#include <iostream>
#include <vector>
#include <string>
#include "mockos/TextFile.h"
#include "mockos/Constants.h"

using namespace std;

int main () {
    cout << "Call methods by derived class" << endl;

    // Create a textFile by derived class and create test vectors
    TextFile textFile("test");
    vector<char> test1 = {'p', 'r', 'i', 'z', 'e'};
    vector<char> test2 = {};
    vector<char> test3 = {'p', ' ', 'p'};

    // Run various tests on TextFiles by derived class
    textFile.write(test1);
    textFile.read();
    textFile.append(test2);
    textFile.read();
    textFile.write(test3);
    textFile.read();

    cout << endl;
    cout << "Call methods by aliased abstract class" << endl;

    // Create a textFile by aliased abstract class
    AbstractFile* p;
    p = &textFile;

    // Run various tests on TextFiles by aliased abstract class
    p->write(test2); // Make textFile.contents blank again
    p->write(test1);
    p->read();
    p->append(test2);
    p->read();
    p->write(test3);
    p->read();

    return SUCCESS;
}