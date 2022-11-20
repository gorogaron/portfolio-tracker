#include "BondDao.h"
#include "fmt/format.h"

bool BondDao::insertBondInputData(const BondInputData& iBondInputData){
    string wCommand = fmt::format("INSERT INTO BOND_input(time, action, amount, interest, expiration) VALUES ('{}', '{}', '{}', '{}', '{}');",
                                  iBondInputData.getDate(),
                                  Common::getStringForEnum(Common::ActivityTypeStringMap, iBondInputData.getActivityType()),
                                  iBondInputData.getAmount(),
                                  iBondInputData.getInterest(),
                                  iBondInputData.getExpiration());
    Dao::connectIfNeeded();
    PGresult* wResult = PQexec(Dao::mDbConnection, wCommand.c_str());

    if (PQresultStatus(wResult) == PGRES_COMMAND_OK){
        return true;
    }
    else {
        // Unable to execute command
        return false;
    }
};