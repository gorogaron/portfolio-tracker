#pragma once

#include <string>
#include <map>
#include <algorithm>

typedef std::string string;

namespace Common{
    
    enum class Currency{
        EUR,
        USD,
        HUF
    };
    extern std::map<string, Currency> CurrencyStringMap;

    enum class AssetType{
        Stock,
        Cash,
        Crypto,
        Bond,
        Funda
    };
    extern std::map<string, AssetType> AssetTypeStringMap;

    enum class ActivityType{
        Buy,
        Sell,
        Income,
        Withdraw
    };
    extern std::map<string, ActivityType> ActivityTypeStringMap;

    template<typename T>
    string getStringForEnum(std::map<string, T> iMap, T iEnumVal){
        auto wElement = find_if(iMap.begin(), iMap.end(), [iEnumVal](std::pair<string, T> iPair){
            return iPair.second == iEnumVal;
        });
        return wElement->first;
    };

}