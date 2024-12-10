#include "mockos/MacroCommand.h"

using namespace std;

// RenameParsingStrategy implements a parsing strategy for the rename macro command
class RenameParsingStrategy : public AbstractParsingStrategy{
public:
    // Parses user input to return a properly formatted vector for rename
    vector<string> parse(string s) override;
};