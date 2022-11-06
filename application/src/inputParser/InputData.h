#pragma once

#include <iostream>
#include "../utils/Common.h"

class InputData{
    friend std::ostream& operator<<(std::ostream& o, const InputData& i);
    public:
        InputData(Common::AssetType iType, string iDate, Common::ActivityType iActivityType);
        virtual bool addToDatabase() const = 0;
        Common::AssetType getType();
    private:
        Common::AssetType mType;
        Common::ActivityType mActivityType;
        string mDate;
};

std::ostream& operator<<(std::ostream& o, const InputData& i);