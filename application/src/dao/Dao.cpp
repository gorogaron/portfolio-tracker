#include "Dao.h"
#include <iostream>

PGconn* Dao::mDbConnection = nullptr;

void Dao::connectIfNeeded(){
    if (!isConnected()){
        mDbConnection = PQconnectdb("host=timescale-db port=5432 dbname=portfolio user=postgres password=1234");
    }
}

bool Dao::isConnected(){
    if (PQstatus(mDbConnection) != CONNECTION_OK) {
        return false;
    }
    else {
        return true;
    }
}