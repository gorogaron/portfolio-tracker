#include <iostream>
#include <stdlib.h>

#include "postgresql/libpq-fe.h"
#include <httplib.h>

int main(){
    // Test PostgreSQL connection
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

    //Test finnhub API
    httplib::Client cli("https://finnhub.io");
    std::string apiKey = "1234";
    auto res = cli.Get("/api/v1/quote?symbol=AAPL&token=" + apiKey);
    std::cout << res->body << std::endl;

}