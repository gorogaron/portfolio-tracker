#include "yahooScraper.h"
#include <curl/curl.h>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


YahooScraper::YahooScraper() {
    
}

YahooScraper& YahooScraper::getInstance() {
    static auto wScraper = YahooScraper();
    return wScraper;
}

size_t YahooScraper::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string YahooScraper::getHistoryicalData(string iTicker, string iStart, string iEnd, Interval iInterval) const {
    const auto wUrl = constructUrl(iTicker, iStart, iEnd, iInterval);
    CURL* wCurl;
    string wResult;

    wCurl = curl_easy_init();
    if (wCurl){
        curl_easy_setopt(wCurl, CURLOPT_URL, wUrl.c_str());
        curl_easy_setopt(wCurl, CURLOPT_WRITEFUNCTION, YahooScraper::WriteCallback);
        curl_easy_setopt(wCurl, CURLOPT_WRITEDATA, &wResult);
        CURLcode res = curl_easy_perform(wCurl);
        curl_easy_cleanup(wCurl);
    }

    json wJsonRes = json::parse(wResult);
    json wJsonPrice;
    json wJsonTimestamp;
    wJsonPrice["close"] = wJsonRes["chart"]["result"][0]["indicators"]["quote"][0]["close"];
    wJsonPrice["timestamp"] = wJsonRes["chart"]["result"][0]["timestamp"];

    std::cout << wJsonPrice.dump() << std::endl;
    return wResult;
}

string YahooScraper::constructUrl(string iTicker, string iStart, string iEnd, Interval iInterval) const {
    return mBaseUrl + "/" +
                iTicker + "?" + 
                "start=" + iStart + "&" +
                "end=" + iEnd + "&" +
                "interval=" + mIntervalString[int(iInterval)];   
}
