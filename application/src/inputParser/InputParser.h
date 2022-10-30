#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "../utils/Common.h"
#include "InputData.h"
#include <memory>

typedef std::fstream fstream;

class InputParser{
    private:
        InputParser();
        void logInputDataReadError(Common::AssetType iAssetType);

        std::vector<std::unique_ptr<InputData>> mInputVector;
    public:
        static InputParser& getInstance();
        bool open(string iPath);
        bool parse();
        bool close();

        const std::vector<std::unique_ptr<InputData>>& getInputs() const;

        fstream mFileStream;
};