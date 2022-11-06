#pragma once

#include "Dao.h"
#include "../inputParser/CashInputData.h"

class CashDao : public Dao{
    public:
    
    static bool insertCashInputData(const CashInputData& iCashInputData);
};