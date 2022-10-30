#include "StockCryptoInputData.h"


StockCryptoInputData::StockCryptoInputData(Common::ActivityType iActivityType, Common::AssetType iAssetType, string iDate, Common::ActivityType iActivity, string iTicker, int iQuantity, double iUnitPrice, Common::Currency iCurrency) : 
InputData(iAssetType, iDate, iActivityType), mActivity(iActivity), mTicker(iTicker), mQuantity(iQuantity), mUnitPrice(iUnitPrice), mCurrency(iCurrency){
};

bool StockCryptoInputData::addToDatabase() const{

}