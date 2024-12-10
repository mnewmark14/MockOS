//
// Created by Malcolm Newmark on 5/6/24.
//

#include <iostream>
#include <sstream>
#include <string>
#include "mockos/TCParsingStrategy.h"

using namespace std;

vector<string> TCParsingStrategy::parse(string s) {
    vector<string> inputs;
    istringstream iss(s);

    string name;
    iss >> name;

    string touchFirst = name;

    //checks to see if '-p' is included in s. If it does, it appends '-p' to the touch input
    if (s.find("-p") != string::npos) {
        touchFirst += " -p";
    }

    //touch command input
    inputs.push_back(touchFirst);
    //cat command input
    inputs.push_back(name);

    return inputs;

}
