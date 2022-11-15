#pragma once

#include "InputData.h"

class BondInputData : public InputData {
    public:
        BondInputData(Common::ActivityType iActivityType, double iAmount, Common::Currency iCurrency, string iDate, double iInterest);
    private:
        double mAmount;
        Common::Currency mCurrency;
        double mInterest;
};