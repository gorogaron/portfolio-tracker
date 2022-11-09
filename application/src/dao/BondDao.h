#pragma once

#include "Dao.h"
#include "../inputParser/BondInputData.h"

class BondDao : public Dao{
    public:
    
    static bool insertBondInputData(const BondInputData& iBondInputData);
};