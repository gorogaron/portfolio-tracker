#pragma once

#include "Dao.h"
#include "../inputParser/StockCryptoInputData.h"

class StockCryptoDao : public Dao{
    public:
    
    static bool insertStockCryptoInputData(const StockCryptoInputData& iStockCryptoInputData);
};