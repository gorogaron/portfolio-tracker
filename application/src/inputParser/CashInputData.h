#pragma once

#include "InputData.h"

class CashInputData : public InputData {
    public:
        CashInputData(Common::ActivityType iActivityType, double iAmount, Common::Currency iCurrency, string iDate);
        virtual bool addToDatabase() const override;
    private:
        double mAmount;
        Common::Currency mCurrency;
};