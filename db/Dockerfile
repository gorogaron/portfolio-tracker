FROM timescale/timescaledb-ha:pg14-latest
USER root

# Install git
RUN apt-get update && \
    apt-get install git -y

# Clone dotfiles
RUN git clone https://github.com/gorogaron/dotfiles.git /tmp/dotfiles && \
    /tmp/dotfiles/setup.sh --force && \
    rm -rf /tmp/dotfiles

USER postgres
RUN /tmp/dotfiles/setup.sh --force