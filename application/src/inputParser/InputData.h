#include "../utils/Common.h"

class InputData{
    public:
        InputData(AssetType iType, string iDate, ActivityType iActivityType);
        virtual bool addToDatabase() const = 0;
    private:
        AssetType mType;
        ActivityType mActivityType;
        string mDate;
};