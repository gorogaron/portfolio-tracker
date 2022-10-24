#include "InputData.h"

class StockCryptoInputData : public InputData {
    public:
        StockCryptoInputData(AssetType iAssetType, string iDate, Activity iActivity, string iTicker,
                             int iQuantity, double iUnitPrice, Currency iCurrency);

    private:
        Activity mActivity;
        string mTicker;
        int mQuantity;
        double mUnitPrice;
        Currency mCurrency;
};