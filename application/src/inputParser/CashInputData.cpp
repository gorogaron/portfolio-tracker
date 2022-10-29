#include "CashInputData.h"


CashInputData::CashInputData(ActivityType iActivityType, double iAmount, Currency iCurrency, string iDate) : 
InputData(AssetType::Cash, iDate, iActivityType), mAmount(iAmount), mCurrency(iCurrency){
};

bool CashInputData::addToDatabase() const{
    
}