/*
 * FSCUtils.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: demensdeum
 */

#include "FSCUtils.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

namespace FlameSteelCore {
namespace Utils {

string stringFromFileAtPath(string path) {
    cout << "Load string from file at path: " << path << endl;
    std::ifstream inputFileStream(path);
    if (!inputFileStream) {
        throw std::system_error(errno, std::system_category(), "failed to open " + path);
    }
    std::stringstream buffer;
    buffer << inputFileStream.rdbuf();
    auto outputString = buffer.str();
    return outputString;
}

int RandomInt(int maximalInt) {

    if (maximalInt == 0) {
        return 0;
    }

    int randomInt = rand() % maximalInt;

    return randomInt;
}

bool RandomBool() {
    return RandomInt(2);
}

shared_ptr<string> localizedString(shared_ptr<string> key) {
    return key;
}


}
}