cmake_minimum_required(VERSION 3.18)

project(PortfolioTrackerApp)

set( SOURCE
    ./src/main.cpp
)

add_executable(PortfolioTrackerApp ${SOURCE})
SET(CMAKE_CXX_FLAGS "-DCPPHTTPLIB_OPENSSL_SUPPORT")
target_link_libraries(PortfolioTrackerApp libpq.so libcrypto.so libssl.so)