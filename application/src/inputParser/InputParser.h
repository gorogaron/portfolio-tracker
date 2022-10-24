#include <fstream>
#include <iostream>
#include <vector>

#include "../utils/Common.h"
#include "InputData.h"

typedef std::fstream fstream;

class InputParser{
    private:
        InputParser();
    public:
        static InputParser& getInstance();
        bool open(string iPath);
        bool parse();
        bool close();

        fstream mFileStream;
        std::vector<InputData*> mInputs;
};