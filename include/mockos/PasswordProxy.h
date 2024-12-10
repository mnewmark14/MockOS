#ifndef MOCKOS_PASSWORDPROXY_H
#define MOCKOS_PASSWORDPROXY_H

#include <iostream>
#include "AbstractFile.h"

using namespace std;

// Enables the user to create password protected files
class PasswordProxy : public AbstractFile {
public:
    // Constructor
    PasswordProxy(AbstractFile *_file, string _password);

    // Destructor
    ~PasswordProxy() override;

    // Returns an actual call to read on protected file if the user enters the correct password
    vector<char> read() override;

    // Returns an actual call to write on protected file if the user enters the correct password
    int write(vector<char> writeage) override;

    // Returns an actual call to append on protected file if the user enters the correct password
    int append(vector<char> appendage) override;

    // Returns the size of the protected file
    unsigned int getSize() override;

    // Returns the name of the protected file
    string getName() override;

    // Returns an actual call to accept on protected file if the user enters the correct password
    void accept(AbstractFileVisitor *afv) override;

    // Creates a copy of the file
    AbstractFile *clone(string newName) override;

private:
    AbstractFile *file;
    string password;
protected:
    // Prompts the user to input the password
    string passwordPrompt();

    // Checks to see if password was inputted properly
    bool passwordChecker(string password);

};

#endif //MOCKOS_PASSWORDPROXY_H