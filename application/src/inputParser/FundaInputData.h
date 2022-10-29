#include "InputData.h"

class FundaInputData : public InputData {
    public:
        FundaInputData(double iAmount, string iDate);
        virtual bool addToDatabase() const override;
    private:
        double mAmount;
};