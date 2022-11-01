FROM gcc:latest

RUN apt update && apt upgrade -y && \
    apt install postgresql postgresql-contrib -y && \
    apt install cmake -y && \
    apt install gdb && \
    apt install pip && \
    pip install conan

RUN curl -o /usr/local/include/httplib.h -s https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h

RUN git clone https://github.com/gorogaron/dotfiles.git /tmp/dotfiles && \
    /tmp/dotfiles/setup.sh -y && \
    rm -rf /tmp/dotfiles

ENV PGHOST=timescale-db
ENV PGPORT=5432
ENV PGDATABASE=portfolio
ENV PGUSER=postgres
ENV PGPASSWORD=1234