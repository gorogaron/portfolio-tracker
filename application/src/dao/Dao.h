#include <postgresql/libpq-fe.h>
#include <memory>

class Dao{
private:
    Dao();
    
    static std::shared_ptr<PGconn> mDbConnection;
    static void connect();
    static bool testConnection();
};