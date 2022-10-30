#include "CashInputData.h"


CashInputData::CashInputData(Common::ActivityType iActivityType, double iAmount, Common::Currency iCurrency, string iDate) : 
InputData(Common::AssetType::Cash, iDate, iActivityType), mAmount(iAmount), mCurrency(iCurrency){
};

bool CashInputData::addToDatabase() const{
    
}