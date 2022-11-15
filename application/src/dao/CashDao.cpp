#include "CashDao.h"
#include "fmt/format.h"

bool CashDao::insertCashInputData(const CashInputData& iCashInputData){
    string wCommand = fmt::format("INSERT INTO cash(time, action, amount, currency) VALUES ('{}', '{}', {}, '{}');",
                                   iCashInputData.getDate(),
                                   Common::getStringForEnum(Common::ActivityTypeStringMap, iCashInputData.getActivityType()),
                                   iCashInputData.getAmount(), 
                                   Common::getStringForEnum(Common::CurrencyStringMap, iCashInputData.getCurrency()));
    
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