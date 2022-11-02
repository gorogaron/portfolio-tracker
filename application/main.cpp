#include <iostream>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <httplib.h>
#include <nlohmann/json.hpp>

#include "yahooScraper.h"
#include "InputParser.h"

using json = nlohmann::json;

int main(){
    // Test PostgreSQL connection
    PGconn* wCon;
    wCon = PQconnectdb("host=timescale-db port=5432 dbname=portfolio user=postgres password=1234");
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

    //Test parser
    auto& wInputParser = InputParser::getInstance();
    wInputParser.open("/portfolio-tracker/db/user-input.txt");
    wInputParser.parse();
    wInputParser.close();
    for (const auto& wInput : wInputParser.getInputs()){
        std::cout << *wInput;
    }

}