#include "InputParser.h"
#include "StockCryptoInputData.h"
#include "CashInputData.h"
#include "BondInputData.h"
#include "FundaInputData.h"

#include <memory>
#include <iostream>
#include <algorithm>

InputParser::InputParser() {
    
}

InputParser& InputParser::getInstance() {
    static InputParser inputParser;
    return inputParser;
}

bool InputParser::open(string iPath) {
    mFileStream.open(iPath, std::fstream::in);
}

bool InputParser::parse() {
    if (!mFileStream.is_open()) {
        return false;
    }

    string wLine;
    while(getline(mFileStream, wLine)){
        string wActivityType;
        string wAssetType;
        std::unique_ptr<InputData> wNewInput = nullptr;
        if (sscanf(wLine.c_str(), "%s %s", wActivityType, wAssetType) == 2){
            switch (AssetTypeStringMap[wAssetType]) {
                case AssetType::Stock:
                case AssetType::Crypto:
                {
                    string wTicker, wDate, wUnitPriceCurrency;
                    double wQuantity, wUnitPrice;
                    if (sscanf(wLine.c_str(), "%*s %*s %s %s %f %f %s", wTicker, wDate, wQuantity, wUnitPrice, wUnitPriceCurrency) == 5){
                        wNewInput = std::unique_ptr<InputData>(new StockCryptoInputData(ActivityTypeStringMap[wActivityType], AssetTypeStringMap[wAssetType], wDate, ActivityTypeStringMap[wActivityType], wTicker,
                                                              wQuantity, wUnitPrice, CurrencyStringMap[wUnitPriceCurrency]));
                    }
                    break;
                }
                case AssetType::Cash:
                {
                    string wCurrency, wDate;
                    double wAmount;
                    if (sscanf(wLine.c_str(), "%*s %*s %f %s %s", wAmount, wCurrency, wDate) == 3){
                        wNewInput = std::unique_ptr<InputData>(new CashInputData(ActivityTypeStringMap[wActivityType], wAmount, CurrencyStringMap[wCurrency], wDate));
                    }
                    break;
                }
                case AssetType::Bond:
                {
                    double wAmount, wInterest;
                    string wDate;
                    if (sscanf(wLine.c_str(), "%*s %*s %f %s %f", wAmount, wDate, wInterest) == 3) {
                        wNewInput = std::unique_ptr<InputData>(new BondInputData(ActivityTypeStringMap[wActivityType], wAmount, Currency::HUF, wDate, wInterest));
                    }
                    break;
                }
                case AssetType::Funda:
                {   
                    double wAmount;
                    string wDate;
                    if (sscanf(wLine.c_str(), "%*s %*s %f %s", wAmount, wDate) == 2){
                        wNewInput = std::unique_ptr<InputData>(new FundaInputData(wAmount, wDate));
                    }
                    break;
                }
                
                default:
                    break;
            }
            if (wNewInput == nullptr){
                logInputDataReadError(AssetTypeStringMap[wAssetType]);
            }
        }
    }

    return true;
}

bool InputParser::close() {
    mFileStream.close();
}

void InputParser::logInputDataReadError(AssetType iAssetType){
    string wAssetTypeString = std::find_if(AssetTypeStringMap.begin(), AssetTypeStringMap.end(), [iAssetType](std::pair<string, AssetType> iPair){
        return iAssetType == iPair.second;
    })->first;
    std::cout << "Failed to read " << wAssetTypeString << " item from input file." << std::endl;
}