#include "InputParser.h"
#include "StockCryptoInputData.h"
#include "CashInputData.h"
#include "BondInputData.h"
#include "FundaInputData.h"

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
        if (wLine[0] == '#'){
            continue;
        }
        char wActivityTypeBuff[25];
        char wAssetTypeBuff[25];
        std::unique_ptr<InputData> wNewInput = nullptr;
        if (sscanf(wLine.c_str(), "%s %s", wActivityTypeBuff, wAssetTypeBuff) == 2){
            string wActivityType(wActivityTypeBuff);
            string wAssetType(wAssetTypeBuff);
            switch (Common::AssetTypeStringMap[wAssetType]) {
                case Common::AssetType::Stock:
                case Common::AssetType::Crypto:
                {
                    char wTicker[200], wDate[200], wUnitPriceCurrency[200];
                    double wQuantity, wUnitPrice;
                    if (sscanf(wLine.c_str(), "%*s %*s %s %s %f %f %s", wTicker, wDate, &wQuantity, &wUnitPrice, wUnitPriceCurrency) == 5){
                        wNewInput = std::unique_ptr<InputData>(new StockCryptoInputData(Common::ActivityTypeStringMap[wActivityType], Common::AssetTypeStringMap[wAssetType], wDate, Common::ActivityTypeStringMap[wActivityType], wTicker,
                                                              wQuantity, wUnitPrice, Common::CurrencyStringMap[wUnitPriceCurrency]));
                    }
                    break;
                }
                case Common::AssetType::Cash:
                {
                    char wCurrencyBuff[25];
                    char wDate[25];
                    double wAmount;
                    if (sscanf(wLine.c_str(), "%*s %*s %f %s %s", &wAmount, wCurrencyBuff, wDate) == 3){
                        string wCurrency(wCurrencyBuff);
                        wNewInput = std::unique_ptr<InputData>(new CashInputData(Common::ActivityTypeStringMap[wActivityType], wAmount, Common::CurrencyStringMap[wCurrency], string(wDate)));
                    }
                    break;
                }
                case Common::AssetType::Bond:
                {
                    double wAmount, wInterest;
                    char wDate[25];
                    if (sscanf(wLine.c_str(), "%*s %*s %f %s %f", &wAmount, wDate, &wInterest) == 3) {
                        wNewInput = std::unique_ptr<InputData>(new BondInputData(Common::ActivityTypeStringMap[wActivityType], wAmount, Common::Currency::HUF, string(wDate), wInterest));
                    }
                    break;
                }
                case Common::AssetType::Funda:
                {   
                    double wAmount;
                    char wDate[25];
                    if (sscanf(wLine.c_str(), "%*s %*s %f %s", &wAmount, wDate) == 2){
                        wNewInput = std::unique_ptr<InputData>(new FundaInputData(wAmount, string(wDate)));
                    }
                    break;
                }
                
                default:
                    break;
            }
            if (wNewInput == nullptr){
                logInputDataReadError(Common::AssetTypeStringMap[wAssetType]);
                return false;
            }
            else {
                mInputVector.push_back(std::move(wNewInput));
            }
        }
    }

    return true;
}

bool InputParser::close() {
    mFileStream.close();
}

void InputParser::logInputDataReadError(Common::AssetType iAssetType){
    string wAssetTypeString = std::find_if(Common::AssetTypeStringMap.begin(), Common::AssetTypeStringMap.end(), [iAssetType](std::pair<string, Common::AssetType> iPair){
        return iAssetType == iPair.second;
    })->first;
    std::cout << "Failed to read " << wAssetTypeString << " item from input file." << std::endl;
}

const std::vector<std::unique_ptr<InputData>>& InputParser::getInputs() const {
    return mInputVector;
}