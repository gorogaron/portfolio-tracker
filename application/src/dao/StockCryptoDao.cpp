#include "StockCryptoDao.h"
#include "fmt/format.h"

bool StockCryptoDao::insertStockCryptoInputData(const StockCryptoInputData& iStockCryptoInputData){

    string wTableName;
    if (iStockCryptoInputData.getType() == Common::AssetType::Stock){
        wTableName = "stock_input";
    }
    else if (iStockCryptoInputData.getType() == Common::AssetType::Crypto){
        wTableName = "crypto_input";
    }

    string wCommand = fmt::format("INSERT INTO {}(time, action, ticker, quantity, unit_price, currency) VALUES ('{}', '{}', '{}', '{}', '{}', '{}');",
                                   wTableName,
                                   iStockCryptoInputData.getDate(),
                                   Common::getStringForEnum(Common::ActivityTypeStringMap, iStockCryptoInputData.getActivityType()),
                                   iStockCryptoInputData.getTicker(),
                                   iStockCryptoInputData.getQuantity(),
                                   iStockCryptoInputData.getUnitPrice(),
                                   Common::getStringForEnum(Common::CurrencyStringMap, iStockCryptoInputData.getCurrency()));
    
    Dao::connectIfNeeded();
    PGresult* wResult = PQexec(Dao::mDbConnection, wCommand.c_str());
    
    if (PQresultStatus(wResult) == PGRES_COMMAND_OK){
        return true;
    }
    else {
        // Unable to execute command
        return false;
    }
};