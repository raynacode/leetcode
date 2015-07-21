class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)
            return 0;
        vector<int> vProf(prices.size(), 0);
        int minVal = prices[0];
        int maxVal = prices[prices.size() - 1];
        int maxProf = 0;
        for (int i = 1; i < prices.size(); i++) {
            minVal = min(minVal, prices[i]);
            maxProf = max(maxProf, prices[i] - minVal);
            vProf[i] = maxProf;
        }
        maxProf = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            maxVal = max(maxVal, prices[i]);
            maxProf = max(maxProf, maxVal - prices[i]);
            vProf[i] += maxProf;
        }
        std::sort(vProf.begin(), vProf.end());
        return vProf[vProf.size() - 1];
    }
};