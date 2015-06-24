class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int sum = 0;
    	int res = std::numeric_limits<int>::min();
    	for (int i = 0; i < nums.size(); i++) {
    		if (sum > 0)
    			sum += nums[i];
    		else
    			sum = nums[i];
    		res = max(res, sum);
    	}
    	return res;
    }
};