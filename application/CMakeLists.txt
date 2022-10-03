cmake_minimum_required(VERSION 3.18)

project(PortfolioTrackerApp)

set( SOURCE
    ./src/main.cpp
)

add_executable(PortfolioTrackerApp ${SOURCE})

target_link_libraries(PortfolioTrackerApp libpq.so)