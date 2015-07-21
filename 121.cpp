class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = numeric_limits<int>::max();
        int maxProf = 0;
        for (int i = 0; i < prices.size(); i++) {
            minVal = min(minVal, prices[i]);
            maxProf = max(maxProf, prices[i] - minVal);
        }
        return maxProf;
    }
};