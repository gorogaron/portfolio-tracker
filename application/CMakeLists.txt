cmake_minimum_required(VERSION 3.18)

project(PortfolioTrackerApp)

find_package(nlohmann_json 3.2.0 REQUIRED)


set( SOURCE
    ./main.cpp
    ./src/yahooScraper/yahooScraper.cpp
    ./src/inputParser/BondInputData.cpp
    ./src/inputParser/CashInputData.cpp
    ./src/inputParser/StockCryptoInputData.cpp
    ./src/inputParser/FundaInputData.cpp
    ./src/inputParser/InputParser.cpp
    ./src/inputParser/InputData.cpp
    ./src/utils/Common.cpp
)

include_directories(
    "./src/yahooScraper"
    "./src/inputParser"
)

add_executable(PortfolioTrackerApp ${SOURCE})
SET(CMAKE_CXX_FLAGS "-DCPPHTTPLIB_OPENSSL_SUPPORT")
target_link_libraries(PortfolioTrackerApp libpq.so libcrypto.so libssl.so libcurl.so nlohmann_json::nlohmann_json)