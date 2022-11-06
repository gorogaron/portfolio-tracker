#include "InputData.h"
#include <algorithm>


InputData::InputData(Common::AssetType iType, string iDate, Common::ActivityType iActivityType) : mType(iType), mDate(iDate), mActivityType(iActivityType) {
    // Do nothing else
}

Common::AssetType InputData::getType(){
    return mType;
}

std::ostream& operator<<(std::ostream& o, const InputData& i){
    string wAssetType = find_if(Common::AssetTypeStringMap.begin(), Common::AssetTypeStringMap.end(), [type = i.mType](std::pair<string, Common::AssetType> iElement){
        return iElement.second == type;
    })->first;
    string wActivityType = find_if(Common::ActivityTypeStringMap.begin(), Common::ActivityTypeStringMap.end(), [type = i.mActivityType](std::pair<string, Common::ActivityType> iElement){
        return iElement.second == type;
    })->first;

    o << wAssetType << " " << wActivityType << std::endl;
    return o;
}
