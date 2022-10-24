#include "InputParser.h"


InputParser::InputParser() {
    
}

InputParser& InputParser::getInstance() {
    static InputParser inputParser;
    return inputParser;
}

bool InputParser::open(string iPath) {
    mFileStream.open(iPath, std::fstream::in);
}

bool InputParser::parse() {
    if (!mFileStream.is_open()) {
        return false;
    }

    string wLine;
    while(getline(mFileStream, wLine)){
         string wAssetTypeString;
         sscanf(wLine.c_str(), "%s", wAssetTypeString);
    }

    return true;
}

bool InputParser::close() {
    mFileStream.close();
}
