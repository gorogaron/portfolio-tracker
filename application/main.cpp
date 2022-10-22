#include <iostream>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <httplib.h>
#include <nlohmann/json.hpp>

#include "yahooScraper.h"

using json = nlohmann::json;

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

    //Test yahoo scraper
    const auto& wYahooScraper = YahooScraper::getInstance();
    auto wRes = wYahooScraper.getHistoryicalData("MSFT", "2021-12-12", "2021-12-12", YahooScraper::Interval::eInterval_1h);

}