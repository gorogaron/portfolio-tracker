#include "FundaInputData.h"


FundaInputData::FundaInputData(double iAmount, string iDate) : 
InputData(AssetType::Funda, iDate, ActivityType::Income), mAmount(iAmount){
};

bool FundaInputData::addToDatabase() const{
    
}