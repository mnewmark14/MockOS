#include "mockos/RenameParsingStrategy.h"
#include <sstream>

using namespace std;

vector<string> RenameParsingStrategy::parse(string s) {
    // Wraps parameter s in istringstream and extracts first two words into existingFile and newName
    istringstream iss(s);
    string existingFile;
    string newName;
    iss >> existingFile >> newName;

    // Properly orders inputs for use by copy then remove commands
    vector<string> inputs = {s, existingFile};
    return inputs;
}
