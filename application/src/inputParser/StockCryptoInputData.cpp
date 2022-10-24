#include "StockCryptoInputData.h"


StockCryptoInputData::StockCryptoInputData(AssetType iAssetType, string iDate, Activity iActivity, string iTicker, int iQuantity, double iUnitPrice, Currency iCurrency) : 
InputData(iAssetType, iDate), mActivity(iActivity), mTicker(iTicker), mQuantity(iQuantity), mUnitPrice(iUnitPrice), mCurrency(iCurrency){
};