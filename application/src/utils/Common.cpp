#include "Common.h"

namespace Common{
    std::map<string, Currency> CurrencyStringMap = 
    {
        {"EUR", Currency::EUR},
        {"USD", Currency::USD},
        {"HUF", Currency::HUF}
    };

    std::map<string, AssetType> AssetTypeStringMap = 
    {
        {"STOCK", AssetType::Stock},
        {"CASH", AssetType::Cash},
        {"CRYPTO", AssetType::Crypto},
        {"BOND", AssetType::Bond},
        {"FUNDA", AssetType::Funda}
    };

    std::map<string, ActivityType> ActivityTypeStringMap = 
    {
        {"BUY", ActivityType::Buy},
        {"SELL", ActivityType::Sell},
        {"INCOME", ActivityType::Income},
        {"WITHDRAW", ActivityType::Withdraw}
    };
}