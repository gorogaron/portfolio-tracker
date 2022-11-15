#include "BondInputData.h"


BondInputData::BondInputData(Common::ActivityType iActivityType, double iAmount, Common::Currency iCurrency, string iDate, double iInterest) : 
InputData(Common::AssetType::Bond, iDate, iActivityType), mAmount(iAmount), mCurrency(iCurrency), mInterest(iInterest){
};