#include "BondInputData.h"


BondInputData::BondInputData(Common::ActivityType iActivityType, double iAmount, Common::Currency iCurrency, string iDate, double iInterest, string iExpiration) : 
InputData(Common::AssetType::Bond, iDate, iActivityType), mAmount(iAmount), mCurrency(iCurrency), mInterest(iInterest), mExpiration(iExpiration){
};

double BondInputData::getAmount() const{
    return mAmount;
}

Common::Currency BondInputData::getCurrency() const{
    return mCurrency;
}

double BondInputData::getInterest() const{
    return mInterest;
}

string BondInputData::getExpiration() const{
    return mExpiration;
}
