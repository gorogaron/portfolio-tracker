FROM timescale/timescaledb-ha:pg14-latest
USER root

# Install git
RUN apt-get update && \
    apt-get install git -y

# Clone dotfiles for root and postgres users
RUN git clone https://github.com/gorogaron/dotfiles.git /tmp/dotfiles && \
    /tmp/dotfiles/setup.sh --force

USER postgres
RUN /tmp/dotfiles/setup.sh --force