#pragma once

#include <string>
#include <map>

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
        Income
    };
    extern std::map<string, ActivityType> ActivityTypeStringMap;

}