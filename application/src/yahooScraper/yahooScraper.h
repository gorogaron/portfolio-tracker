#pragma once

#include <curl/curl.h>
#include <string>

typedef std::string string;

class YahooScraper{

public:
    enum class Interval {
        eInterval_1m,
        eInterval_2m,
        eInterval_5m,
        eInterval_15m,
        eInterval_30m,
        eInterval_60m,
        eInterval_90m,
        eInterval_1h,
        eInterval_1d,
        eInterval_5d,
        eInterval_1wk,
        eInterval_1mo,
        eInterval_3mo,
        eInterval_max
    };

    static YahooScraper& getInstance();
    
    string getHistoryicalData(string iTicker, string iStart, string iEnd, Interval iInterval) const;

private:
    const string mIntervalString[int(Interval::eInterval_max)] = {
        "1m",
        "2m",
        "5m",
        "15m",
        "30m",
        "60m",
        "90m",
        "1h",
        "1d",
        "5d",
        "1wk",
        "1mo",
        "3mo"
    };
    const string mBaseUrl = "https://query2.finance.yahoo.com/v8/finance/chart/";

    YahooScraper();

    string constructUrl(string iTicker, string iStart, string iEnd, Interval iInterval) const;

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};