#include "Dao.h"

std::shared_ptr<PGconn> Dao::mDbConnection = nullptr;

void Dao::connect(){
    mDbConnection = std::make_shared<PGconn>(PQconnectdb("host=timescale-db port=5432 dbname=portfolio user=postgres password=1234"));
}

bool Dao::testConnection(){
    if (PQstatus(mDbConnection.get()) != CONNECTION_OK) {
        return false;
    }
    else {
        return true;
    }
}