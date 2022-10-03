#include <iostream>
#include <stdlib.h>

#include "postgresql/libpq-fe.h"

int main(){
    PGconn* wCon;

    wCon = PQconnectdb("");

    if (PQstatus(wCon) != CONNECTION_OK)
    {
        std::cout << "Connection failed!" << std::endl;
    }
    else
    {
        std::cout << "Connection established!" << std::endl;
    }

    PQfinish(wCon);
}