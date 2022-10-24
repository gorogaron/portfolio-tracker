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
    StateBond,
};
std::map<string, AssetType> AssetTypeStringMap = 
{
    {"STOCK", AssetType::Stock},
    {"CASH", AssetType::Cash},
    {"CRYPTO", AssetType::Crypto},
    {"STATEBOND", AssetType::StateBond}
};

enum class Activity{
    Buy,
    Sell
};
std::map<string, AssetType> AssetTypeStringMap = 
{
    {"BUY", AssetType::Stock},
    {"SELL", AssetType::Cash}
};