#pragma once

#include "InputData.h"

class StockCryptoInputData : public InputData {
    public:
        StockCryptoInputData(Common::ActivityType iActivityType, Common::AssetType iAssetType, string iDate, Common::ActivityType iActivity, string iTicker,
                             int iQuantity, double iUnitPrice, Common::Currency iCurrency);

        Common::ActivityType getActivity() const;
        string getTicker() const;
        int getQuantity() const;
        double getUnitPrice() const;
        Common::Currency getCurrency() const;
    private:
        Common::ActivityType mActivity;
        string mTicker;
        int mQuantity;
        double mUnitPrice;
        Common::Currency mCurrency;
};