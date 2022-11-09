#include "BondDao.h"
#include "fmt/format.h"

bool BondDao::insertBondInputData(const BondInputData& iBondInputData){
    string wCommand = fmt::format("INSERT INTO BOND(time, action, amount, interest, expiration) VALUES ({}, {}, {}, {}, {});",
                                  "2022-11-2", "BUY", "3333", "22", "2022-11-15");
    Dao::connectIfNeeded();
    PGresult* wResult = PQexec(Dao::mDbConnection, wCommand.c_str());

    return true;
};