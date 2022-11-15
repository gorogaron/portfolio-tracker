#include <fmt/format.h>
#include "CashInputData.h"

CashInputData::CashInputData(Common::ActivityType iActivityType, double iAmount, Common::Currency iCurrency, string iDate) : 
InputData(Common::AssetType::Cash, iDate, iActivityType), mAmount(iAmount), mCurrency(iCurrency){
};

double CashInputData::getAmount() const{
    return mAmount;
}

Common::Currency CashInputData::getCurrency() const{
    return mCurrency;
}