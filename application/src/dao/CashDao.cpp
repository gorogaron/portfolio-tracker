#include "CashDao.h"

bool CashDao::insertCashInputData(const CashInputData& iCashInputData){
    string wCommand = "INSERT INTO cash(time, action, amount, currency) VALUES ('2022-11-03', 'INCOME', 0, 'EUR');";
    Dao::connectIfNeeded();
    PGresult* wResult = PQexec(Dao::mDbConnection, wCommand.c_str());

    return true;
};