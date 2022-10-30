#include "FundaInputData.h"


FundaInputData::FundaInputData(double iAmount, string iDate) : 
InputData(Common::AssetType::Funda, iDate, Common::ActivityType::Income), mAmount(iAmount){
};

bool FundaInputData::addToDatabase() const{
    
}