#pragma once

#include <string>
#include <map>

typedef std::string string;

enum class Currency{
    EUR,
    USD,
    HUF
};
std::map<string, Currency> CurrencyStringMap = 
{
    {"EUR", Currency::EUR},
    {"USD", Currency::USD},
    {"HUF", Currency::HUF}
};


enum class AssetType{
    Stock,
    Cash,
    Crypto,
    Bond,
    Funda
};
std::map<string, AssetType> AssetTypeStringMap = 
{
    {"STOCK", AssetType::Stock},
    {"CASH", AssetType::Cash},
    {"CRYPTO", AssetType::Crypto},
    {"BOND", AssetType::Bond},
    {"FUNDA", AssetType::Funda}
};

enum class ActivityType{
    Buy,
    Sell,
    Income
};
std::map<string, ActivityType> ActivityTypeStringMap = 
{
    {"BUY", ActivityType::Buy},
    {"SELL", ActivityType::Sell},
    {"INCOME", ActivityType::Income}
};