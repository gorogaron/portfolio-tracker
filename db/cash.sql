CREATE TABLE cash(
    time TIMESTAMPTZ NOT NULL,
    currency TEXT NOT NULL,
    amount NUMERIC(12,2) NOT NULL
);

INSERT INTO cash (time, currency, amount) VALUES
    (NOW(), 'HUF', 12568),
    (NOW(), 'USD', 152.21),
    (NOW(), 'EUR', 23.22);