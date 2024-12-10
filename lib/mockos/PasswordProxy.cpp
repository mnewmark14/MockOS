#include "mockos/PasswordProxy.h"
#include "mockos/Constants.h"
#include <string>

// Constructor, initializes the file and password member variables
PasswordProxy::PasswordProxy(AbstractFile *_file, string _password) : file(_file), password(_password) {}

// Destructor, deletes the file member variable
PasswordProxy::~PasswordProxy() {
    delete file;
}

string PasswordProxy::passwordPrompt() {
    string inputtedPassword;

    // Prompts the user for input and reads to inputtedPassword
    cout << "Enter your password: " << endl;
    cin >> inputtedPassword;

    // Returns the user inputted password
    return inputtedPassword;
}

bool PasswordProxy::passwordChecker(string checkPassword) {
    // Verifies that the checkPassword parameter equals the password member variable
    if (password == checkPassword) {
        return true;
    } else {
        return false;
    }
}

vector<char> PasswordProxy::read() {
    // Verifies the password was entered correctly
    if (passwordChecker(passwordPrompt())) {

        // Reads the file to the user
        return file->read();
    } else {

        // Returns a blank vector otherwise
        return {};
    }
}

int PasswordProxy::write(vector<char> writeage) {

    // Stores the result of the user's password entry attempt
    bool correct = passwordChecker(passwordPrompt());

    if (correct) {

        // Writes to the file if the password was entered correctly
        return file->write(writeage);
    } else {

        // Returns an error if the password was entered incorrectly
        return PASSWORDS_DONT_MATCH;
    }
}

int PasswordProxy::append(vector<char> appendage) {

    // Stores the result of the user's password entry attempt
    bool correct = passwordChecker(passwordPrompt());

    if (correct) {

        // Appends to the file if the password was entered correctly
        return file->append(appendage);
    } else {

        // Returns an error if the password was entered incorrectly
        return PASSWORDS_DONT_MATCH;
    }
}

unsigned int PasswordProxy::getSize() {

    // Returns the size of the file member variable
    return file->getSize();
}

string PasswordProxy::getName() {

    // Returns the name of the file member variable
    return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor *afv) {
    if (passwordChecker(passwordPrompt())) {
        file->accept(afv);
    }
}

AbstractFile *PasswordProxy::clone(string newName) {
    auto* newFile = this->file->clone(newName);
    auto* newProxy = new PasswordProxy(newFile, this->password);
    return newProxy;
}