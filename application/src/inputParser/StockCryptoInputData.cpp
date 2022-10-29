#include "StockCryptoInputData.h"


StockCryptoInputData::StockCryptoInputData(ActivityType iActivityType, AssetType iAssetType, string iDate, ActivityType iActivity, string iTicker, int iQuantity, double iUnitPrice, Currency iCurrency) : 
InputData(iAssetType, iDate, iActivityType), mActivity(iActivity), mTicker(iTicker), mQuantity(iQuantity), mUnitPrice(iUnitPrice), mCurrency(iCurrency){
};

bool StockCryptoInputData::addToDatabase() const{

}