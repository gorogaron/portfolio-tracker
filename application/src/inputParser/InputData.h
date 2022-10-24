#include "../utils/Common.h"

class InputData{
    public:
        InputData(AssetType iType, string iDate);
        virtual bool addToDatabase() const = 0;
    private:
        AssetType mType;
        string mDate;
};