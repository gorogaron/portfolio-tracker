#include "StockCryptoInputData.h"


StockCryptoInputData::StockCryptoInputData(Common::ActivityType iActivityType, Common::AssetType iAssetType, string iDate, Common::ActivityType iActivity, string iTicker, int iQuantity, double iUnitPrice, Common::Currency iCurrency) : 
InputData(iAssetType, iDate, iActivityType), mActivity(iActivity), mTicker(iTicker), mQuantity(iQuantity), mUnitPrice(iUnitPrice), mCurrency(iCurrency){
};

Common::ActivityType StockCryptoInputData::getActivity() const{
    return mActivity;
}

string StockCryptoInputData::getTicker() const{
    return mTicker;
}

int StockCryptoInputData::getQuantity() const{
    return mQuantity;
}

double StockCryptoInputData::getUnitPrice() const{
    return mUnitPrice;
}

Common::Currency StockCryptoInputData::getCurrency() const{
    return mCurrency;
}
