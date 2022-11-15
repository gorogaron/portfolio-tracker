#pragma once

#include "InputData.h"

class FundaInputData : public InputData {
    public:
        FundaInputData(double iAmount, string iDate);
    private:
        double mAmount;
};