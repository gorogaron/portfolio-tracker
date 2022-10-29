#include "InputData.h"

class StockCryptoInputData : public InputData {
    public:
        StockCryptoInputData(ActivityType iActivityType, AssetType iAssetType, string iDate, ActivityType iActivity, string iTicker,
                             int iQuantity, double iUnitPrice, Currency iCurrency);
        virtual bool addToDatabase() const override;
    private:
        ActivityType mActivity;
        string mTicker;
        int mQuantity;
        double mUnitPrice;
        Currency mCurrency;
};