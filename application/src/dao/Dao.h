#pragma once

#include <postgresql/libpq-fe.h>
#include <memory>

class Dao{
    public:

    // PGconn is opaque, so no smart pointer can be used
    static PGconn* mDbConnection;

    private:
    Dao();
    
    protected:
    static void connectIfNeeded();
    static bool isConnected();
};