cmake_minimum_required(VERSION 3.18)

project(PortfolioTrackerApp)

find_package(nlohmann_json 3.2.0 REQUIRED)


set( SOURCE
    ./main.cpp
    ./src/yahooScraper/yahooScraper.cpp
)

include_directories(
    "./src/yahooScraper"
)

add_executable(PortfolioTrackerApp ${SOURCE})
SET(CMAKE_CXX_FLAGS "-DCPPHTTPLIB_OPENSSL_SUPPORT")
target_link_libraries(PortfolioTrackerApp libpq.so libcrypto.so libssl.so libcurl.so nlohmann_json::nlohmann_json)