#include "InputData.h"

class BondInputData : public InputData {
    public:
        BondInputData(ActivityType iActivityType, double iAmount, Currency iCurrency, string iDate, double iInterest);
        virtual bool addToDatabase() const override;
    private:
        double mAmount;
        Currency mCurrency;
        double mInterest;
};