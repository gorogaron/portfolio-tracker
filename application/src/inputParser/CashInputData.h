#include "InputData.h"

class CashInputData : public InputData {
    public:
        CashInputData(ActivityType iActivityType, double iAmount, Currency iCurrency, string iDate);
        virtual bool addToDatabase() const override;
    private:
        double mAmount;
        Currency mCurrency;
};