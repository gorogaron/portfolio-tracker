#pragma once

#include "InputData.h"

class CashInputData : public InputData {
    public:
        CashInputData(Common::ActivityType iActivityType, double iAmount, Common::Currency iCurrency, string iDate);

        double getAmount() const;
        Common::Currency getCurrency() const;
    private:
        double mAmount;
        Common::Currency mCurrency;
};