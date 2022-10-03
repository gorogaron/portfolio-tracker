FROM gcc:latest

RUN apt update && apt upgrade -y && \
    apt install postgresql postgresql-contrib -y && \
    apt install cmake -y

ENV PGHOST=timescale-db
ENV PGPORT=5432
ENV PGDATABASE=portfolio
ENV PGUSER=postgres
ENV PGPASSWORD=1234