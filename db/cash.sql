CREATE TYPE CASH_ACTION AS ENUM ('INCOME', 'WITHDRAW');

CREATE TABLE CASH_INPUT(
    time TIMESTAMPTZ NOT NULL,
    action CASH_ACTION NOT NULL,
    amount NUMERIC(12,2) NOT NULL,
    currency TEXT NOT NULL
);


/*INSERT INTO cash (time, currency, amount) VALUES
    (NOW(), 'HUF', 12568),
    (NOW(), 'USD', 152.21),
    (NOW(), 'EUR', 23.22);*/