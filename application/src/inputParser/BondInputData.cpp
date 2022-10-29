#include "BondInputData.h"


BondInputData::BondInputData(ActivityType iActivityType, double iAmount, Currency iCurrency, string iDate, double iInterest) : 
InputData(AssetType::Bond, iDate, iActivityType), mAmount(iAmount), mCurrency(iCurrency), mInterest(iInterest){
};

bool BondInputData::addToDatabase() const{
    
}