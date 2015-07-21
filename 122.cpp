class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)
            return 0;
        int maxProf = 0;
        int prof = 0;
        int minVal = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i - 1]) {
                maxProf += prof > 0 ? prof : 0;
                minVal = prices[i];
                prof = 0;
            }
            else if (prices[i] > prices[i - 1]){
                prof = max(prof, prices[i] - minVal);
            }
        }
        maxProf += prof > 0 ? prof : 0;
        return maxProf;
    }
};