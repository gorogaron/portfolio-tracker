FROM gcc:latest

RUN apt update && apt upgrade -y && \
    apt install postgresql postgresql-contrib -y && \
    apt install cmake -y && \
    apt install gdb

RUN curl -o /usr/local/include/httplib.h -s https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h

RUN curl -o /tmp/json -s https://github.com/nlohmann/json.git && \
    cd /tmp/json && mkdir build && cd build && \
    cmake ../ && make -j8 install && \
    cd /tmp && rm -rf json


ENV PGHOST=timescale-db
ENV PGPORT=5432
ENV PGDATABASE=portfolio
ENV PGUSER=postgres
ENV PGPASSWORD=1234