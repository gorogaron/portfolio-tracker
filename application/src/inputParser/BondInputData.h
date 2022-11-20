#pragma once

#include "InputData.h"

class BondInputData : public InputData {
    public:
        BondInputData(Common::ActivityType iActivityType, double iAmount, Common::Currency iCurrency, string iDate, double iInterest, string iExpiration);
        double getAmount() const;
        Common::Currency getCurrency() const;
        double getInterest() const;
        string getExpiration() const;
    private:
        double mAmount;
        Common::Currency mCurrency;
        double mInterest;
        string mExpiration;
};